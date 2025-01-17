# $Id: third_party_install.meta.mk 489461 2016-01-13 14:40:24Z ucko $

#################################################################
#
# Third party DLLs installation makefile
#
# Author: Andrei Gourianov
#
#################################################################


# Build configuration name
INTDIR = $(INTDIR:.\=)
ALTDIR = $(INTDIR:VTune_=)
!IF ("$(INTDIR)"=="$(ALTDIR)")
ALTDIR = $(INTDIR:Unicode_=)
!ENDIF

# Extensions of files to copy
EXTENSIONS         = dll pdb manifest

# MSVC DLLs
#  MSVC_SRC must be defined elsewhere (eg, in command line)
#MSVCRT_SRC = \\snowman\win-coremake\Lib\ThirdParty\msvc\msvc71\7.1\bin
#MSVCRT_SRC = \\snowman\win-coremake\Lib\ThirdParty\msvc\msvc8\8\bin

MSVCRT_SRC = \\snowman\win-coremake\Lib\ThirdParty\msvc\$(MSVC_SRC)\bin



#################################################################
# Source folders
#
# x_BINPATH macros are defined in Makefile.third_party.mk 
# generated by project_tree_builder
#

PTB_GENERATED = $(THIRDPARTY_MAKEFILES_DIR)\$(INTDIR)\Makefile.third_party.mk
!IF EXIST($(PTB_GENERATED))
!INCLUDE $(PTB_GENERATED)
!ELSE
!ERROR  $(PTB_GENERATED)  not found
!ENDIF


BERKELEYDB_SRC = $(BERKELEYDB_BINPATH)\$(INTDIR)
!IF !EXIST($(BERKELEYDB_SRC))
BERKELEYDB_SRC = $(BERKELEYDB_BINPATH)\$(ALTDIR)
!ENDIF

GNUTLS_SRC = $(GNUTLS_BINPATH)\$(INTDIR)
!IF !EXIST($(GNUTLS_SRC))
GNUTLS_SRC = $(GNUTLS_BINPATH)\$(ALTDIR)
!ENDIF

GLEW_SRC = $(GLEW_BINPATH)\$(INTDIR)
!IF !EXIST($(GLEW_SRC))
GLEW_SRC = $(GLEW_BINPATH)\$(ALTDIR)
!ENDIF

LZO_SRC = $(LZO_BINPATH)\$(INTDIR)
!IF !EXIST($(LZO_SRC))
LZO_SRC = $(LZO_BINPATH)\$(ALTDIR)
!ENDIF

MSSQL_SRC = $(MSSQL_BINPATH)\$(INTDIR)
!IF !EXIST($(MSSQL_SRC))
MSSQL_SRC = $(MSSQL_BINPATH)\$(ALTDIR)
!ENDIF

MYSQL_SRC = $(MYSQL_BINPATH)\$(INTDIR)
!IF !EXIST($(MYSQL_SRC))
MYSQL_SRC = $(MYSQL_BINPATH)\$(ALTDIR)
!ENDIF

OPENSSL_SRC = $(OPENSSL_BINPATH)\$(INTDIR)
!IF !EXIST($(OPENSSL_SRC))
OPENSSL_SRC = $(OPENSSL_BINPATH)\$(ALTDIR)
!ENDIF

SQLITE_SRC = $(SQLITE_BINPATH)\$(INTDIR)
!IF !EXIST($(SQLITE_SRC))
SQLITE_SRC = $(SQLITE_BINPATH)\$(ALTDIR)
!ENDIF

SQLITE3_SRC = $(SQLITE3_BINPATH)\$(INTDIR)
!IF !EXIST($(SQLITE3_SRC))
SQLITE3_SRC = $(SQLITE3_BINPATH)\$(ALTDIR)
!ENDIF

# SYBASE_SRC = $(SYBASE_BINPATH)\$(INTDIR)
# !IF !EXIST($(SYBASE_SRC))
# SYBASE_SRC = $(SYBASE_BINPATH)\$(ALTDIR)
# !ENDIF
SYBASE_SRC = $(SYBASE_BINPATH)\$(INTDIR:Debug=Release)
!IF !EXIST($(SYBASE_SRC))
SYBASE_SRC = $(SYBASE_BINPATH)\$(ALTDIR:Debug=Release)
!ENDIF

WXWIDGETS_SRC = $(WXWIDGETS_BINPATH)\$(INTDIR)
!IF !EXIST($(WXWIDGETS_SRC))
WXWIDGETS_SRC = $(WXWIDGETS_BINPATH)\$(ALTDIR)
!ENDIF

WXWINDOWS_SRC = $(WXWINDOWS_BINPATH)\$(INTDIR)
!IF !EXIST($(WXWINDOWS_SRC))
WXWINDOWS_SRC = $(WXWINDOWS_BINPATH)\$(ALTDIR)
!ENDIF

XALAN_SRC = $(XALAN_BINPATH)\$(INTDIR)
!IF !EXIST($(XALAN_SRC))
XALAN_SRC = $(XALAN_BINPATH)\$(ALTDIR)
!ENDIF

XERCES_SRC = $(XERCES_BINPATH)\$(INTDIR)
!IF !EXIST($(XERCES_SRC))
XERCES_SRC = $(XERCES_BINPATH)\$(ALTDIR)
!ENDIF

LIBXML_SRC = $(LIBXML_BINPATH)\$(INTDIR)
!IF !EXIST($(LIBXML_SRC))
LIBXML_SRC = $(LIBXML_BINPATH)\$(ALTDIR)
!ENDIF

LIBXSLT_SRC = $(LIBXSLT_BINPATH)\$(INTDIR)
!IF !EXIST($(LIBXSLT_SRC))
LIBXSLT_SRC = $(LIBXSLT_BINPATH)\$(ALTDIR)
!ENDIF

VDB_SRC = $(VDB_BINPATH)



#################################################################

INSTALL_CMD = \
	@if exist "$*" ( for %%e in ($(EXTENSIONS)) do @( \
	    if exist "$*\*.%%e" ( \
	      for /f "delims=" %%i in ('dir /a-d/b "$*\*.%%e"') do @( \
	        xcopy /Y /D /F "$*\%%i" "$(INSTALL_BINPATH)" ) \
	    )) \
	) else (echo WARNING:   "$*" not found)

CLEAN_CMD = \
	@if exist "$*" ( for %%e in ($(EXTENSIONS)) do @( \
	    if exist "$*\*.%%e" ( \
	      for /f "delims=" %%i in ('dir /a-d/b "$*\*.%%e"') do @( \
	        if exist "$(INSTALL_BINPATH)\%%i" ( \
	          echo $(INSTALL_BINPATH)\%%i & del /F "$(INSTALL_BINPATH)\%%i" )))) \
	) else (echo WARNING:   "$*" not found)



#################################################################
# Targets
#

$(BERKELEYDB_SRC).berkeleydb_install :
	@echo ---- & echo Copying BerkeleyDB DLLs & $(INSTALL_CMD)
$(BERKELEYDB_SRC).berkeleydb_clean :
	@echo ---- & echo Deleting BerkeleyDB DLLs & $(CLEAN_CMD)
install_berkeleydb : $(BERKELEYDB_SRC).berkeleydb_install
clean_berkeleydb : $(BERKELEYDB_SRC).berkeleydb_clean



$(GNUTLS_SRC).gnutls_install :
	@echo ---- & echo Copying GNUTLS DLLs & $(INSTALL_CMD)
$(GNUTLS_SRC).gnutls_clean :
	@echo ---- & echo Deleting GNUTLS DLLs & $(CLEAN_CMD)
install_gnutls : $(GNUTLS_SRC).gnutls_install
clean_gnutls : $(GNUTLS_SRC).gnutls_clean



$(GLEW_SRC).glew_install :
	@echo ---- & echo Copying GLEW DLLs & $(INSTALL_CMD)
$(GLEW_SRC).glew_clean :
	@echo ---- & echo Deleting GLEW DLLs & $(CLEAN_CMD)
install_glew : $(GLEW_SRC).glew_install
clean_glew : $(GLEW_SRC).glew_clean



$(LZO_SRC).lzo_install :
	@echo ---- & echo Copying LZO DLLs & $(INSTALL_CMD)
$(LZO_SRC).lzo_clean :
	@echo ---- & echo Deleting LZO DLLs & $(CLEAN_CMD)
install_lzo : $(LZO_SRC).lzo_install
clean_lzo : $(LZO_SRC).lzo_clean



$(MYSQL_SRC).mysql_install :
	@echo ---- & echo Copying MySQL DLLs & $(INSTALL_CMD)
$(MYSQL_SRC).mysql_clean :
	@echo ---- & echo Deleting MySQL DLLs & $(CLEAN_CMD)
install_mysql : $(MYSQL_SRC).mysql_install
clean_mysql : $(MYSQL_SRC).mysql_clean



$(MSSQL_SRC).mssql_install :
	@echo ---- & echo Copying MSSQL DLLs & $(INSTALL_CMD)
$(MSSQL_SRC).mssql_clean :
	@echo ---- & echo Deleting MSSQL DLLs & $(CLEAN_CMD)
install_mssql : $(MSSQL_SRC).mssql_install
clean_mssql : $(MSSQL_SRC).mssql_clean



$(OPENSSL_SRC).openssl_install :
	@echo ---- & echo Copying OpenSSL DLLs & $(INSTALL_CMD)
$(OPENSSL_SRC).openssl_clean :
	@echo ---- & echo Deleting OpenSSL DLLs & $(CLEAN_CMD)
install_openssl : $(OPENSSL_SRC).openssl_install
clean_openssl : $(OPENSSL_SRC).openssl_clean



$(SQLITE_SRC).sqlite_install :
	@echo ---- & echo Copying SQLite DLLs & $(INSTALL_CMD)
$(SQLITE_SRC).sqlite_clean :
	@echo ---- & echo Deleting SQLite DLLs & $(CLEAN_CMD)
install_sqlite : $(SQLITE_SRC).sqlite_install
clean_sqlite : $(SQLITE_SRC).sqlite_clean



$(SQLITE3_SRC).sqlite3_install :
	@echo ---- & echo Copying SQLite3 DLLs & $(INSTALL_CMD)
$(SQLITE3_SRC).sqlite3_clean :
	@echo ---- & echo Deleting SQLite3 DLLs & $(CLEAN_CMD)
install_sqlite3 : $(SQLITE3_SRC).sqlite3_install
clean_sqlite3 : $(SQLITE3_SRC).sqlite3_clean



$(SYBASE_SRC).sybase_install :
	@echo ---- & echo Copying Sybase DLLs & $(INSTALL_CMD)
$(SYBASE_SRC).sybase_clean :
	@echo ---- & echo Deleting Sybase DLLs & $(CLEAN_CMD)
install_sybase : $(SYBASE_SRC).sybase_install
clean_sybase : $(SYBASE_SRC).sybase_clean



$(WXWIDGETS_SRC).wxwidgets_install :
	@echo ---- & echo Copying wxWidgets DLLs & $(INSTALL_CMD)
$(WXWIDGETS_SRC).wxwidgets_clean :
	@echo ---- & echo Deleting wxWidgets DLLs & $(CLEAN_CMD)
install_wxwidgets : $(WXWIDGETS_SRC).wxwidgets_install
clean_wxwidgets : $(WXWIDGETS_SRC).wxwidgets_clean



$(WXWINDOWS_SRC).wxwindows_install :
	@echo ---- & echo Copying wxWindows DLLs & $(INSTALL_CMD)
$(WXWINDOWS_SRC).wxwindows_clean :
	@echo ---- & echo Deleting wxWindows DLLs & $(CLEAN_CMD)
install_wxwindows : $(WXWINDOWS_SRC).wxwindows_install
clean_wxwindows : $(WXWINDOWS_SRC).wxwindows_clean



$(XALAN_SRC).xalan_install :
	@echo ---- & echo Copying Xalan DLLs & $(INSTALL_CMD)
$(XALAN_SRC).xalan_clean :
	@echo ---- & echo Deleting Xalan DLLs & $(CLEAN_CMD)
install_xalan : $(XALAN_SRC).xalan_install
clean_xalan : $(XALAN_SRC).xalan_clean



$(XERCES_SRC).xerces_install :
	@echo ---- & echo Copying Xerces DLLs & $(INSTALL_CMD)
$(XERCES_SRC).xerces_clean :
	@echo ---- & echo Deleting Xerces DLLs & $(CLEAN_CMD)
install_xerces : $(XERCES_SRC).xerces_install
clean_xerces : $(XERCES_SRC).xerces_clean



$(LIBXML_SRC).libxml_install :
	@echo ---- & echo Copying LIBXML DLLs & $(INSTALL_CMD)
$(LIBXML_SRC).libxml_clean :
	@echo ---- & echo Deleting LIBXML DLLs & $(CLEAN_CMD)
install_libxml : $(LIBXML_SRC).libxml_install
clean_libxml : $(LIBXML_SRC).libxml_clean



$(LIBXSLT_SRC).libxslt_install :
	@echo ---- & echo Copying LIBXSLT DLLs & $(INSTALL_CMD)
$(LIBXSLT_SRC).libxslt_clean :
	@echo ---- & echo Deleting LIBXSLT DLLs & $(CLEAN_CMD)
install_libxslt : $(LIBXSLT_SRC).libxslt_install
clean_libxslt : $(LIBXSLT_SRC).libxslt_clean


VDB_ORIG = $(INSTALL_BINPATH)\ncbi-vdb-md.dll
VDB_COPY = $(INSTALL_BINPATH)\ncbi-vdb-dll-md.dll
$(VDB_SRC).vdb_install :
	@echo ---- & echo Copying VDB DLLs & $(INSTALL_CMD)
# The trailing * suppresses a spurious prompt, per
# http://stackoverflow.com/a/26034267/1231
	@if exist "$(VDB_ORIG)" xcopy /Y /D /F "$(VDB_ORIG)" "$(VDB_COPY)"*
$(VDB_SRC).vdb_clean :
	@echo ---- & echo Deleting VDB DLLs & $(CLEAN_CMD)
	@if exist "$(VDB_COPY)" ( echo $(VDB_COPY) & del /f "$(VDB_COPY)" )
install_vdb : $(VDB_SRC).vdb_install
clean_vdb : $(VDB_SRC).vdb_clean



# -----------------------------------------
# MSVC RT DLLs are not included into 'all'

msvc_install : dirs $(MSVCRT_SRC).msvc_install

install_msvc : msvc_install
msvc_clean : $(MSVCRT_SRC).msvc_clean
clean_msvc : msvc_clean
msvc_rebuild : msvc_clean msvc_install

$(MSVCRT_SRC).msvc_install :
	@echo ---- & echo Copying MSVC DLLs & $(INSTALL_CMD)
$(MSVCRT_SRC).msvc_clean :
	@echo ---- & echo Deleting MSVC DLLs & $(CLEAN_CMD)
	
