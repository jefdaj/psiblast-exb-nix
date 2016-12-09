# $Id: Makefile.segmasker.app 500573 2016-05-05 16:42:41Z gouriano $

REQUIRES = objects algo

ASN_DEP = seq

APP = segmasker
SRC = segmasker

LIB_ = xobjsimple xalgosegmask $(BLAST_LIBS) $(OBJMGR_LIBS)
LIB = $(LIB_:%=%$(STATIC))

LIBS = $(CMPRS_LIBS) $(NETWORK_LIBS) $(DL_LIBS) $(ORIG_LIBS)

CXXFLAGS = $(FAST_CXXFLAGS)
LDFLAGS  = $(FAST_LDFLAGS)


WATCHERS = camacho