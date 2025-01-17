#! /bin/sh
#
# $Id: new_module.sh.in 484944 2015-11-17 16:42:34Z ucko $
# Authors:  Eugene Vasilchenko, NCBI;  Aaron Ucko, NCBI

top_srcdir="/root/blasttest/source_upload/ncbi-blast-2.5.0+-src_psiblastexb/c++"
build_root="/root/blasttest/source_upload/ncbi-blast-2.5.0+-src_psiblastexb/c++/ReleaseMT"
bindir=$build_root/bin
libdir=$build_root/lib

if test -z "$CHECK_TIMEOUT"; then
    CHECK_TIMEOUT=900
    export CHECK_TIMEOUT
    exec $top_srcdir/scripts/common/check/check_exec.sh $0 "$@"
fi

rm -f check_exec.pid

# Some useful common functions (such as COMMON_AddRunpath)
. ${top_srcdir}/scripts/common/common.sh

# detect root directory of current tree (which may be incomplete!)
p="`pwd`"
mp=
while true; do
    d="`basename \"$p\"`"
    p="`dirname \"$p\"`"
    if test -d "$p/src" && test -d "$p/include"; then
        break
    fi
    if test -z "$mp"; then
        mp="$d"
    else
        mp="$d/$mp"
    fi
    if test "$p" = "/"; then
        echo "Root directory not found"
        exit 1
    fi
done
# here $p is root directory, $mp is module path so $p/src/$mp is current dir

makemodule=
for f in build-system/Makefile.module Makefile.module; do
    for d in $p $top_srcdir $NCBI/c++; do
        if test -f $d/src/$f; then
            makemodule=$d/src/$f
            break
        fi
    done
    test -z "$makemodule"  ||  break
done

if test -z "$makemodule"; then
    echo "Makefile.module not found"
    exit 1
fi

# define function which will get variable value from file
# Synopsis: getvar <var_name> <file_name>
getvar () {
    grep "^[ 	]*$1[ 	]*=" "$2" | head -n1 |
        sed "s/^[ 	]*$1[ 	]*=[ 	]*//" | sed "s/[ 	]*$//"
}

# detect command arguments
case "$1" in
    --dtd)
        ext="dtd"
        EXT="DTD"
        shift
        ;;
    --schema | --xsd)
        ext="xsd"
        EXT="XSD"
        shift
        ;;
    --soap | --wsdl)
        ext="wsdl"
        EXT="WSDL"
        shift
	;;
    *)
        ext="asn"
        EXT="ASN"
        ;;
esac
case "$1" in
    *.$ext)
        module="`basename \"$1\" .$ext`"
        spec="$1"
        shift;;
    *.module)
        module="`basename \"$1\" .module`"
        shift;;
    '') if test -f *.module; then
            module="`basename *.module .module`"
        else
            echo "Usage: $0 [module]"
            exit 1
        fi;;
    *)
        module="$1";
        shift;;
esac

if test -f "$module.module"; then
    if test -z "$asn"; then
        spec="`getvar MODULE_$EXT \"$module.module\"`"
    fi
    imports="`getvar MODULE_IMPORT \"$module.module\"`"
else
    echo "File $module.module not found. Using defaults..."
fi
if test -z "$spec"; then
    spec="$module.$ext"
fi

# now $spec is source ASN.1 specification or XML DTD or schema
# $module.module is module description file
# check files
if test -f "$spec"; then
    :
else
    echo "Source file $spec not found."
    exit 1
fi

# Try to find imports
impdeps=
impfiles=
space=
need_main=false
for i in $imports; do
    found=no
    for d in "$p" "$top_srcdir"; do
        for x in asn xsd dtd wsdl; do
            if test -f "$d/src/$i.$x"; then
                impdeps="${impdeps}${space}${d}/src/$i.$x"
                impfiles="${impfiles}${space}$i.$x"
                found=yes
            fi
            [ $found = no ] || break
        done
        [ $found = no ] || break
        need_main=true
    done
    if [ $found = no ]; then
          echo "Import file $i not found."
          exit 1
    fi
    space=' '
done

# detect datatool program path
datatool=

if test "$PREBUILT_DATATOOL_EXE" = bootstrap; then
    : # Don't otherwise look for prebuilt installations
elif test -n "$PREBUILT_DATATOOL_EXE"; then
    datatool=$PREBUILT_DATATOOL_EXE
elif test -x "$NCBI_DATATOOL_PATH/datatool"; then
    datatool=$NCBI_DATATOOL_PATH/datatool
else # elif test -n "$NCBI"; then
    ncbi_platform=`COMMON_DetectPlatform`
    inst_root=/net/snowman/vol/export2/win-coremake/App/Ncbi/cppcore/datatool
    version=`cat $top_srcdir/src/build-system/datatool_version.txt`
    if "$inst_root/$ncbi_platform/$version/datatool" -version >/dev/null 2>&1; \
    then
        datatool=$inst_root/$ncbi_platform/$version/datatool
    fi
fi

if test -z "$datatool"; then # keep looking
    if test "`echo $bindir/*`" = "$bindir/*"; then
        # empty or non-existent (--without-execopy?)
        bindir=$build_root/build/serial/datatool
    fi

    if test -x "$bindir/datatool"; then
        datatool=$bindir/datatool
        COMMON_AddRunpath "$libdir"
    else
        echo "Unable to find datatool." >&2
        exit 2
    fi
fi

# guess the make command, if it is not specified in the $MAKE env. variable
if test -z "$MAKE" ; then
    case "`uname`" in
      CYGWIN* | Darwin | Linux | SunOS) MAKE=make;;
      *) MAKE=gmake;;
    esac
fi

# figure out what search path to specify
if test "$top_srcdir" = "$p"  -o  "$need_main" = false; then
    search="$p/src"
else
    search="$p/src,$top_srcdir/src"
fi

# run command
case "$MAKE" in
    *\ -s* ) ;;
    * )
        echo $MAKE -f "$makemodule" "MODULE=$module" "MODULE_PATH=$mp" \
             "MODULE_ASN=$spec" "MODULE_IMPORT='$imports'" \
             "IMPDEPS='$impdeps'" "IMPFILES='$impfiles'" "top_srcdir=$p" \
             "DATATOOL=$datatool" "MODULE_SEARCH=$search" "$@"
        ;;
esac
$MAKE -f "$makemodule" "MODULE=$module" "MODULE_PATH=$mp" "MODULE_ASN=$spec" \
      "MODULE_IMPORT=$imports" "IMPDEPS=$impdeps" "IMPFILES=$impfiles" \
      "top_srcdir=$p" "DATATOOL=$datatool" "MODULE_SEARCH=$search" "$@"
