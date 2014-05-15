#preprocessor flags(-I -D)
AM_CPPFLAGS= -fPIC\
-I/home/NewHadoop/hadoop/hadoop-1.0.3/src/c++/libhdfs\
-I/home/NewHadoop/java/jdk1.7.0_45/include\
-I/home/NewHadoop/java/jdk1.7.0_45/include/linux

#linker flags(-L)
AM_LDFLAGS=-lc -lm -lrt -lhdfs -ljvm
#-L/home/NewHadoop/java/jdk1.7.0_45/jre/lib/amd64/server\
#-L/home/NewHadoop/hadoop/hadoop-1.0.3/c++/Linux-amd64-64/lib

noinst_LIBRARIES=libclaimshdfs.a
libclaimshdfs_a_SOURCES = ClaimsHDFS.cpp ClaimsHDFS.h
libclaimshdfs_a_LIBADD = /home/NewHadoop/hadoop/hadoop-1.0.3/c++/Linux-amd64-64/lib/libhdfs.a\
/home/NewHadoop/java/jdk1.7.0_45/jre/lib/amd64/server/libjvm.so\
/home/NewHadoop/hadoop/hadoop-1.0.3/c++/Linux-amd64-64/lib/libhdfs.so

#为什么这里的jni.h加不进去呢？遇到了这个问题
#在这里可以加入.a和.h文件
#AM_CPPFLAGS = -I/home/NewHadoop/hadoop/hadoop-1.0.3/src/c++/libhdfs

#notation:
#生成.a文件，下面的.so文件中有了就不需要在写-l了
#ar cru libclaimshdfs.a ClaimsHDFS.o /home/NewHadoop/hadoop/hadoop-1.0.3/c++/Linux-amd64-64/lib/libhdfs.a /home/NewHadoop/java/jdk1.7.0_45/jre/lib/amd64/server/libjvm.so /home/NewHadoop/hadoop/hadoop-1.0.3/c++/Linux-amd64-64/lib/libhdfs.so
