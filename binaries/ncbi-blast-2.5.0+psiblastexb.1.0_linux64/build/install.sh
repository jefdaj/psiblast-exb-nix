#! /bin/sh

# $Id: install.sh.in 117476 2008-01-16 16:44:07Z ucko $
# Author:  Denis Vakatov, NCBI 
#
###########################################################################
# 
#   Install the built libs, apps, and configured headers and makefiles from
#   this tree to another directory -- in a way that would allow "external"
#   users to use them.
#
#   Note:  non-configurable headers, sources, makefiles, scripts and docs
#          (which can be shared by several builds) must be installed
#          separately, using script "scripts/common/impl/install.sh".
#
###########################################################################

echo "[`date`]"

svn_location=`echo '$HeadURL: https://svn.ncbi.nlm.nih.gov/repos/toolkit/release/blast/2.5.0/c++/src/build-system/install.sh.in $' | sed "s%\\$[H]eadURL: *\\([^$][^$]*\\) \\$.*%\\1%"`
svn_revision=`echo '$Revision: 117476 $' | sed "s%\\$[R]evision: *\\([^$][^$]*\\) \\$.*%\\1%"`

script_name=`basename $0`
script_dir=`dirname $0`
script_dir=`(cd "${script_dir}" ; pwd)`

run_dir=`pwd`
run_cmd="$0 $*"

old_srcdir='/root/blasttest/source_upload/ncbi-blast-2.5.0+-src_psiblastexb/c++'
build_dir=`(cd "${script_dir}/.." ; pwd)`
install_dir="$1"

relocate_flags="--copy-times"

#####  USAGE

Usage()
{
  cat <<EOF 1>&2
Usage:
   $script_name <install_dir> [--without-bin] [--with-object-files]
        [--srcdir=DIR] [--drop-suffix]

Synopsis:
   Install NCBI C++ build tree -- built libs, apps, and configured headers
   and makefiles.
   (Hint: to install the source tree, use "c++/scripts/common/impl/install.sh".)

Arguments:
   <install_dir>       -- where to install (this can be either a name of
                          pre-installed top source dir, or a name of build dir)
   --move              -- remove the original build dir on success
   --without-bin       -- do not install executables (from "bin/" dir)
   --with-object-files -- install object files (*.o) -- necessary for proper
                          debugging when using WorkShop
   --srcdir=DIR        -- required if <install_dir> is an absolute path to a
                          directory which (or whose parent) is not a NCBI C++
                          top source directory
   --drop-suffix       -- when adjusting paths embedded in makefiles, replace
                          directory names of the form "c++*" (e.g. "c++.new")
                          with "c++" to allow for more graceful switch-overs.

Script's:  Subversion location/revision, run directory, and run command:
   $svn_location | r$svn_revision
   $run_dir
   $run_cmd

ERROR:  $1
EOF
# This comment supplies another ' to work around an emacs highlighting bug.

  kill $$
  exit 1
}


#####  ARGS

test -n "$install_dir"  ||  Usage "<install_dir> argument missing"

shift
for x_arg in "$@" ; do
  case "$x_arg" in
    --without-bin      )  with_bin="no" ;;
    --with-object-files)  with_object_files="yes" ;;
    --move             )  with_move="yes" ;;
    --srcdir=*         )  new_srcdir=`echo "$x_arg" | sed 's%--srcdir=%%'` ;;
    --drop-suffix      )  relocate_flags="$relocate_flags $x_arg" ;;
    *                  )  Usage "Unknown argument \"$x_arg\""
  esac
done


#####  DIRS  

test -z "$new_srcdir"  -o  -d "$new_srcdir"  || \
     echo "[WARNING]  Top source dir does not exist:  $new_srcdir"

if test -f "$install_dir/include/corelib/ncbistd.hpp" ; then
   # <install_dir> is an existing top source dir
   if test -z "$new_srcdir" ; then
      new_srcdir="$install_dir"
   else
      echo "[WARNING]  Top source dir discrepancy;  using $new_srcdir"
   fi
   install_dir="$install_dir/`basename $build_dir`"
else
   # is <install_dir> is just under an existing top source dir?
   x_srcdir=`echo "$install_dir" | sed 's%/\. *$%%' | sed 's%/$%%'`
   if test -d "$x_srcdir" ; then
      x_srcdir="$x_srcdir/.."
   else
      x_srcdir=`dirname "$x_srcdir"`
   fi
   if test -f "$x_srcdir/include/corelib/ncbistd.hpp" ; then
      if test -z "$new_srcdir" ; then
         new_srcdir="$x_srcdir"
      else
         echo "[WARNING]  Top source dir discrepancy;  using $new_srcdir"
      fi
   fi
fi

test -d "$new_srcdir"   &&  new_srcdir=`(cd "${new_srcdir}" ; pwd)`
test -d "$install_dir"  &&  install_dir=`(cd "${install_dir}" ; pwd)`


#####  INFO

cat <<EOF
Installing C++ Toolkit build:
  from:     $build_dir
  to:       $install_dir
  sources:  ${new_srcdir:-auto detect}

EOF


#####  INSTALL

# Sanity checks
test -z "$new_srcdir"  &&  \
   Usage "Source dir is not specified (neither can it be auto-detected)"
test -r "$install_dir"  -a  ! -f "$install_dir/inc/ncbiconf_unix.h"  &&  \
   Usage "Afraid to install to a dir of unknown structure:  $install_dir"
test "$install_dir" = "$build_dir"  &&  \
   Usage "Cannot install to itself"

# Directories to install
install_dirs="lib status inc"
all_install_dirs="$install_dirs bin build"
test "$with_bin" != "no"  &&  install_dirs="bin $install_dirs"

# Prepare an empty dir for the installation
if test -d $install_dir ; then
   # Delete previous installation
   for d in $all_install_dirs ; do 
      test ! -r "$install_dir/$d"  ||  rm -rf "$install_dir/$d"  ||  \
         Usage "Cannot delete $install_dir/$d"
   done
else
   # Create new dir
   mkdir -p "$install_dir"  || Usage "Cannot create install dir:  $install_dir"
   install_dir=`(cd "${install_dir}" ; pwd)`
fi

# Copy dirs to the install dir;  use TAR to preserve symbolic links, if any
case "`uname`" in
  Darwin ) bs=63 ;;
  *      ) bs=200 ;;
esac
if test "`uname`" = Darwin -a -x /usr/bin/ditto; then
   for d in $install_dirs ; do
      ditto -rsrcFork $build_dir/$d $install_dir/$d
      test $? -eq 0  ||  Usage "Failed copy to:  $install_dir/$d"
   done
else
   for d in $install_dirs ; do
      ( cd $build_dir  &&  tar cfb - $bs $d ) |  \
        ( cd $install_dir  &&  tar xfb - $bs )
      test $? -eq 0  ||  Usage "Failed copy to:  $install_dir/$d"
   done
fi

# Fix gbench-related symlinks
if test -d "$install_dir/bin/.gbench/bin"; then
    (cd "$install_dir/bin/.gbench/bin"  &&  \
     rm -f gbench-bin gbench_plugin_scan  &&  \
     ln -s ../../gbench-bin ../../gbench_plugin_scan .)
     rm -f $install_dir/bin/gbench  &&  \
     ln -s .gbench/bin/run-gbench.sh $install_dir/bin/gbench
fi

# Remove various unneeded files
files="\
status/config.cache"

( cd $install_dir  &&  rm -f $files ) 

# Copy files to the install build dir...
install_builddir="$install_dir/build"

mkdir "$install_builddir"  ||  Usage "Failed to create dir:  $install_builddir"
(cd $script_dir  &&  for f in Makefile.* *.sh *.cfg; do
   case $f in
      reconfigure.sh) continue      ;; # skip (inappropriate)
      Makefile.*)     type=makefile ;;
      *.sh)           type=script   ;;
      *.cfg)          type=config   ;;
   esac
   cp -p $f "$install_builddir/"  ||  \
     Usage "Failed to copy $type to $install_builddir/$f"
done)

#    ...and adjust some for the new $(builddir)

chmod a+x $install_builddir/relocate.sh
(cd $new_srcdir && $install_builddir/relocate.sh $relocate_flags)

# Also copy object files if requested (necessary for debugging info with
# WorkShop)

if test "$with_object_files" = "yes"; then
   echo "Copying object files (this may take a while)"
   # Can we skip SunWS_cache?
   (cd $build_dir/build && find . -name "*.o" -print |\
    cpio -pd $install_builddir)
fi

# Preserve top-level timestamps
touch -r $build_dir/build $install_builddir
touch -r $build_dir       $install_dir

#####  MOVE mode (remove the original build dir)

test "$with_move" = "yes"  &&  rm -rf "$build_dir"


#####  DONE

echo "DONE"
