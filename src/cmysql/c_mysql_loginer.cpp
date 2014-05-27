/*
 * CMysqlLoginer.cpp
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#include "c_mysql_loginer.h"
#include "c_mysql_server.h"
#include "c_mysql_handshake_packet.h"

//CMysqlLoginer::CMysqlLoginer():buffer_(2*1024*1024) {
CMysqlLoginer::CMysqlLoginer() {

}

CMysqlLoginer::~CMysqlLoginer() {

}

int CMysqlLoginer::login(easy_connection_t* c) {
	cout<<"登录处理"<<endl;
	cout<<"调试！"<<endl;
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
	cout<<"服务器向客户端发送握手报文！组装handshake报文发送！"<<endl;
	int ret;
	cout<<"输出c->fd: "<<c->fd<<endl;
	cout<<"输出c->idle_time: "<<c->idle_time<<endl;
	cout<<"输出c->seq: "<<c->seq<<endl;
	CMysqlHandshakePacket packet;
//	ThreadSpecificBuffer::Buffer *thread_buffer=buffer_.get_buffer();
//	ObDataBuffer out_buffer(thread_buffer->current(),thread_buffer->remain());
	ObDataBuffer out_buffer;
	packet.set_thread_id(c->seq);
//	out_buffer.get_position()=0;
//	ret=packet.serialize(out_buffer.get_data(),out_buffer.get_capacity(),out_buffer.get_position());
//	ret=write_data(c->fd,out_buffer.get_data(),out_buffer.get_position());
	return ret;
}

int CMysqlLoginer::parse_packet(easy_connection_t* c) {
	cout<<"进入parse_packet解析报文阶段！"<<endl;
}

int CMysqlLoginer::check_privilege(easy_connection_t* c) {

}

void CMysqlLoginer::set_c_server(CMysqlServer *server) {
	server_=server;
}

int CMysqlLoginer::write_data(int fd,char* buffer,int length){
  int ret=0;
  const char* buff = buffer;
  int count = 0;
  while(0==ret&&length>0&&(count=write(fd,buff,length))!=0){
	  if(-1==count){
		  if(errno==EINTR){
			  continue;
		  }
		  else{
			  ret=0;
		  }
      }
      buff+=count;
      length-=count;
  }
  return ret;
}

