#只要是调用了动态链接库中的.h文件的，无论这个调用有多深，都需要将.h文件加到这个模块中
AM_CPPFLAGS= -fPIC\
-I/home/NewHadoop/hadoop/hadoop-1.0.3/src/c++/libhdfs\
-I/home/NewHadoop/java/jdk1.7.0_45/include\
-I/home/NewHadoop/java/jdk1.7.0_45/include/linux

AM_LDFLAGS=-lc -lm -lrt

noinst_LIBRARIES=libsort.a
libsort_a_SOURCES = SortAlgorithms.cpp \
					SortAlgorithms.h  

#.a中加入外层的.o文件的写法
#引用
libsort_a_LIBADD = ../../Log.o ../sec/libsec.a

#libcommon_a_LDFLAGS= -ldl -lm -lpthread
#include_HEADERS=AVLtree.h Heap.h Btree.h BStree.h 
#EXTRA_DIST = AVLtree.h Heap.h Btree.h BStree.h