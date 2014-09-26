#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
#AC_INIT(htmlcxx.cc)
#AM_INIT_AUTOMAKE(findscholarships, 0.1)
AC_INIT(findscholarships, version-0.1)
AM_INIT_AUTOMAKE([-Wall gnu check-news 1.10])
AM_CONFIG_HEADER([config.h])
#AM_DISABLE_STATIC

DX_HTML_FEATURE([ON])
#DX_CHM_FEATURE([OFF])
#DX_CHI_FEATURE([OFF])
#DX_MAN_FEATURE([OFF])
#DX_RTF_FEATURE([OFF])
#DX_XML_FEATURE([OFF])
#DX_PDF_FEATURE([OFF])
#DX_PS_FEATURE([OFF])
#DX_INIT_DOXYGEN([dmcs],[doxygen.cfg],[doc])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_LIBTOOL

#
# check for libcurl
#
LIBCURL_CHECK_CONFIG([], [], [], [AC_MSG_ERROR([could not find CURL library. Download it at http://curl.haxx.se/.])])

# Checks for libraries.
# Replace `main' with a function in -lfl:
AC_CHECK_LIB(fl, main)
AC_CHECK_LIB(iconv, iconv_open)


# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME

# Checks for library functions.

AC_LANG_CPLUSPLUS
CXXFLAGS="$CXXFLAGS -DDEFAULT_CSS=\"\\\"$datadir/htmlcxx/css/default.css\\\"\""

# checking for boost libs
BOOST_REQUIRE([1.43.0])
BOOST_SMART_PTR
BOOST_STRING_ALGO
BOOST_TOKENIZER
BOOST_IOSTREAMS
BOOST_GRAPH #right now, we don't care about the libboost-graph shared library
BOOST_PROGRAM_OPTIONS
BOOST_SYSTEM
#BOOST_THREADS
BOOST_SERIALIZATION
BOOST_TEST
BOOST_DATE_TIME
BOOST_ASIO

AC_CONFIG_FILES([
	Makefile
	include/Makefile
	include/html/Makefile
	include/css/Makefile
	include/utilities/Makefile
	include/tracker/Makefile
	src/Makefile 
	src/html/Makefile 
	src/css/Makefile
	src/utilities/Makefile
	src/tracker/Makefile
])

AC_OUTPUT(htmlcxx.pc)
