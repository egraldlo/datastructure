AM_CPPFLAGS= -fPIC
AM_LDFLAGS= -lc -lm -lrt -lpthread -lboost_serialization

#include_HEADERS = affinity.h AVLtree.h Barrier.h\
#				BarrierTest.h BitMap.h daemon.h\
#				exception.h fork.h HashTable.h Heap.h\
#				pro_cus.h processor.h RegisterChild.h SChild1.h SParent.h\
#				PL.h Compute.h
				
#bin_PROGRAMS = cppforwork

#cppforwork_SOURCES = affinity.cpp AVLtree.cpp Barrier.cpp\
#				BarrierTest.cpp BitMap.cpp daemon.cpp\
#				exception.cpp fork.cpp HashTable.cpp Heap.cpp pro_cus.cpp\
#				processor.cpp RegisterChild.cpp SChild1.cpp SParent.cpp\
#				PL.cpp choose.cpp Compute.cpp\
#				cpp_for_work.cpp

include_HEADERS = affinity.h\
				BitMap.h daemon.h\
				Barrier.h BarrierTest.h pro_cus.h\
				fork.h HashTable.h exception.h\
				processor.h RegisterChild.h SChild1.h SParent.h\
				PL.h Compute.h
				
bin_PROGRAMS = cppforwork

cppforwork_SOURCES = affinity.cpp\
				BitMap.cpp daemon.cpp\
				Barrier.cpp BarrierTest.cpp pro_cus.cpp\
				fork.cpp HashTable.cpp exception.cpp\
				processor.cpp RegisterChild.cpp SChild1.cpp SParent.cpp\
				PL.cpp choose.cpp Compute.cpp\
				cpp_for_work.cpp
				
SUBDIRS = common 
DIST_SUBDIRS = common 