AM_CPPFLAGS= -fPIC \
-I/usr/include/easy
#凡是递归包含这些头文件的目录都要在makefile中写

AM_LDFLAGS=-lc -lm -lrt -lpthread

noinst_LIBRARIES=libcmysql.a
libcmysql_a_SOURCES = \
	c_mysql_server.cpp							c_mysql_server.h \
	c_mysql_command_queue_thread.cpp 			c_mysql_command_queue_thread.h \
	c_mysql_callback.cpp						c_mysql_callback.h \
	c_mysql_handshake_packet.cpp				c_mysql_handshake_packet.h \
	c_mysql_loginer.cpp				            c_mysql_loginer.h

#生成静态连接库的时候需要用*_a_LIBADD而不是*_a_LDADD
libcmysql_a_LIBADD = /usr/lib64/libeasy.a