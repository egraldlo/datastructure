/*
 * CMysqlCallback.cpp
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#include "c_mysql_callback.h"

CMysqlCallback::CMysqlCallback() {

}

CMysqlCallback::~CMysqlCallback() {

}

int CMysqlCallback::encode(easy_request_t* r, void* packet) {
	cout<<"在CMysqlCallback的encode函数中！"<<endl;
}

void* CMysqlCallback::decode(easy_message_t* m) {
	cout<<"在CMysqlCallback的decode函数中！"<<endl;
}

int CMysqlCallback::on_connect(easy_connection_t* c) {
	cout<<"在CMysqlCallback的on_connect函数中！"<<endl;
	int ret=0;
	if(NULL==c||NULL==c->handler){
		cout<<"链接处理错出"<<endl;
	}
	else{
		CMysqlServer* server = reinterpret_cast<CMysqlServer*>(c->handler->user_data);
		ret=server->login_handler(c);
		if(0!=ret){
			ret=1;
			cout<<"登录错误！"<<endl;
		}
		else{
			ret=0;
		}
	}
	return ret;
}

int CMysqlCallback::on_disconnect(easy_connection_t* c) {
	cout<<"在CMysqlCallback的on_disconnect函数中！"<<endl;
}

int CMysqlCallback::process(easy_request_t* r) {
	cout<<"在CMysqlCallback的process函数中！"<<endl;
}

uint64_t CMysqlCallback::get_packet_id(easy_connection_t* c, void* packet) {
	cout<<"在CMysqlCallback的get_packet_id函数中！"<<endl;
}

int CMysqlCallback::clean_up(easy_request_t *r, void *apacket) {
	cout<<"在CMysqlCallback的clean_up函数中！"<<endl;
}
