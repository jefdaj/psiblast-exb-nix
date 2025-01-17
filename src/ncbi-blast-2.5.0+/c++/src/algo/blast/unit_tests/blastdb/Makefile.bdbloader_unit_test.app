# $Id: Makefile.bdbloader_unit_test.app 500512 2016-05-05 13:14:49Z gouriano $

APP = bdbloader_unit_test
SRC = bdbloader_unit_test

CPPFLAGS = -DNCBI_MODULE=BLASTDB $(ORIG_CPPFLAGS) $(BOOST_INCLUDE) -I../

LIB_ = test_boost $(BLAST_INPUT_LIBS) $(BLAST_LIBS) $(OBJMGR_LIBS)
LIB = $(LIB_:%=%$(STATIC))

LIBS = $(NETWORK_LIBS) $(CMPRS_LIBS) $(DL_LIBS) $(ORIG_LIBS)
LDFLAGS = $(FAST_LDFLAGS)

REQUIRES = objects Boost.Test.Included

CHECK_REQUIRES = MT in-house-resources
CHECK_CMD = bdbloader_unit_test
CHECK_COPY = data
CHECK_TIMEOUT = 600


WATCHERS = madden camacho
