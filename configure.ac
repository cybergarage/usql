############################################################################
#
# uSQL for C++
#
############################################################################

AC_INIT([usqlcc], [0.8])
AM_CONFIG_HEADER(config.h)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(include/usql/SQLParser.h)
AM_INIT_AUTOMAKE([subdir-objects])

##############################
# Constants
##############################

# ANTLR3C version.
LIBANTLR3C_VERSION=3.2

##############################
# Checks for programs.
##############################

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_LANG_CPLUSPLUS

##############################
# Checks for header files.
##############################

AC_HEADER_STDC

##############################
# Checks for libtool.
##############################

AC_ARG_WITH(libtool,
	AS_HELP_STRING([--with-libtool],
		       [use libtool to build the library (default = yes)]),
		       [],
		       [with_libtool=yes])
AM_CONDITIONAL(HAVE_LIBTOOL, test $with_libtool = yes)

##############################
# Checks for ANTLR3C
##############################

AC_CHECK_LIB([antlr3c],[main],,[AC_MSG_ERROR(uSQL for C++ needs ANTLR3C >= $LIBANTLR3C_VERSION)])

##############################
# Checks for pthread
##############################

AC_CHECK_LIB([pthread],[main],,[AC_MSG_ERROR(uSQL for C++  needs POSIX thread library)]) 

##############################
# Checks for other headers.
##############################

AC_CHECK_HEADERS([stdint.h])

##############################
# Checks for other functions.
##############################

AC_CHECK_FUNCS([fopen])

##############################
# Checks for ANTLR 3.4
##############################

AC_MSG_CHECKING(antlr3StringStreamNew)
AC_TRY_COMPILE([
#include <antlr3.h>
void func()
{
  antlr3StringStreamNew(
        (pANTLR3_UINT8)"", 
        ANTLR3_ENC_UTF8,
        (ANTLR3_UINT32)0,
        (pANTLR3_UINT8)"");
}
],
[],
[AC_MSG_RESULT(yes)
AC_DEFINE([USQL_USE_ANTLR3_STRINGSTREAMNEW],1,[antlr3StringStreamNew])],
[AC_MSG_RESULT(no)]
)

##############################
# Checks for enable options.
##############################

AC_ARG_ENABLE([examples], AC_HELP_STRING([--enable-examples], [ builds examples (default = no) ]), [build_examples="yes"], [])
AM_CONDITIONAL(EXAMPLES,test "$build_examples" = yes)
if [ test "$build_examples" = yes ]; then
	AC_CHECK_LIB([crypto],[main],,[AC_MSG_ERROR(uSQL examples need OpenSSL)])
	AC_CHECK_LIB([edit],[main],,[AC_MSG_ERROR(uSQL examples need libedit)])
	AC_CHECK_LIB([mysqlclient],[main],,[AC_MSG_ERROR(uSQL examples need libmysqlclient)])
	AC_CHECK_LIB([memcached],[main],,[AC_MSG_ERROR(uSQL examples need libmemcached)])
	AC_CHECK_LIB([leveldb],[main],,[AC_MSG_ERROR(uSQL examples need leveldb)])
	AC_CHECK_LIB([boost_filesystem],[main],,[AC_MSG_ERROR(uSQL unittests need boost::filesystem)])
fi

AC_ARG_ENABLE([unittests], AC_HELP_STRING([--enable-unittests], [ builds unittests (default = no) ]), [build_unittests="yes"], [])
AM_CONDITIONAL(UNITTESTS,test "$build_unittests" = yes)
if [ test "$build_unittests" = yes ]; then
	AC_CHECK_LIB([boost_unit_test_framework],[main],,[AC_MSG_ERROR(uSQL unittests need boost::unit_test_framework)])
	AC_CHECK_LIB([boost_system],[main],,[AC_MSG_ERROR(uSQL unittests need boost::system)])
	AC_CHECK_LIB([boost_filesystem],[main],,[AC_MSG_ERROR(uSQL unittests need boost::filesystem)])
fi

##############################
# Makefiles
##############################

AC_OUTPUT([
Makefile
include/Makefile
lib/Makefile
lib/unix/Makefile
unittest/Makefile
unittest/unix/Makefile
examples/Makefile
examples/leveldb/Makefile
examples/leveldb/unix/Makefile
examples/sqlparse/Makefile
examples/sqlparse/unix/Makefile
examples/sqlproxy/Makefile
examples/sqlproxy/unix/Makefile
])
