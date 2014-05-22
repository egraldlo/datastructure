/*
 * CMysqlLoginer.cpp
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#include "c_mysql_loginer.h"

#include "c_mysql_server.h"

CMysqlLoginer::CMysqlLoginer() {

}

CMysqlLoginer::~CMysqlLoginer() {

}

int CMysqlLoginer::login(easy_connection_t* c) {
	cout<<"登录处理"<<endl;
	int ret;
	//将握手报文发送到客户端
	ret=handshake(c);//use
    //解析登录认证
	//ret = parse_packet(c);//use
	//发送认证结果报文
    //ret = check_privilege(c);//use
	return ret;
}

int CMysqlLoginer::handshake(easy_connection_t* c) {
	cout<<"服务器向客户端发送握手报文！"<<endl;
	int ret;

	return ret;
}

int CMysqlLoginer::parse_packet(easy_connection_t* c) {

}

int CMysqlLoginer::check_privilege(easy_connection_t* c) {

}

void CMysqlLoginer::set_c_server(CMysqlServer *server) {
	server_=server;
}
