#现在写的动态链接库是两个地方都需要写include的文件，这里要想办法将系统中的hadoop_home指定
AM_CPPFLAGS= -fPIC\
-I/home/NewHadoop/hadoop/hadoop-1.0.3/src/c++/libhdfs\
-I/home/NewHadoop/java/jdk1.7.0_45/include\
-I/home/NewHadoop/java/jdk1.7.0_45/include/linux

#全局变量，链接的时候需要被所有的目标使用
#LDADD = /home/casa/maintenance/hadoop/hadoop-1.0.3/c++/Linux-amd64-64/lib/libhdfs.a

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

#生成可执行文件是用LDADD，但是生成.a文件是用LIBADD，
#后面.o是需要加入的，有没有优雅点的方法呢？但如果只是.h文件呢？
cppforwork_LDADD = sec/libsec.a sync/libsync.a tree/libtree.a sec/thir/libthir.a ../Log.o

#如果有多层依赖的话，要在第一层的makefile中写上第三层.a的依赖，但是这个地方是可以优化的感觉。
treetest_LDADD = sec/libsec.a tree/libtree.a sort/libsort.a external/libclaimshdfs.a a/liba.a b/libb.a
		 
SUBDIRS = tree sec sync sort external a b
DIST_SUBDIRS = tree sec sync sort external a b