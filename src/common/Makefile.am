AM_CPPFLAGS= -fPIC
AM_LDFLAGS=-lc -lm -lrt

lib_LTLIBRARIES=libcommon.la

libcommon_la_SOURCES = AVLtree.cpp Heap.cpp Btree.cpp 
libcommon_la_LDFLAGS= -ldl -lm -lpthread

include_HEADERS=AVLtree.h Heap.h Btree.h
 
EXTRA_DIST = AVLtree.h Heap.h Btree.h