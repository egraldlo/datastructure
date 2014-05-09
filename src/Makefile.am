AM_CPPFLAGS= -fPIC
AM_LDFLAGS= -lc -lm -lrt -lpthread -lboost_serialization

include_HEADERS = affinity.h\
				BitMap.h daemon.h\
				fork.h HashTable.h exception.h\
				processor.h RegisterChild.h SChild1.h SParent.h\
				PL.h Compute.h
				
bin_PROGRAMS =  cppforwork treetest 

cppforwork_SOURCES = affinity.cpp\
				BitMap.cpp daemon.cpp\
				fork.cpp HashTable.cpp exception.cpp\
				processor.cpp RegisterChild.cpp SChild1.cpp SParent.cpp\
				PL.cpp choose.cpp Compute.cpp\
				cpp_for_work.cpp
				
treetest_SOURCES = TreeTest.cpp

cppforwork_LDADD = sec/libsec.a sync/libsync.a tree/libtree.a
treetest_LDADD = tree/libtree.a
				 
SUBDIRS = tree sec sync
DIST_SUBDIRS = tree sec sync