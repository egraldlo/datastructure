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
	ret = parse_packet(c);//use
	//发送认证结果报文
    ret = check_privilege(c);//use
//    getchar();
	return ret;
}

int CMysqlLoginer::handshake(easy_connection_t* c) {
	cout<<"服务器向客户端发送握手报文！组装handshake报文发送！"<<endl;
	int ret;
	cout<<"输出c->fd: "<<c->fd<<endl;
	cout<<"输出c->idle_time: "<<c->idle_time<<endl;
	cout<<"输出c->seq: "<<c->seq<<endl;
	CMysqlHandshakePacket packet;
	char *buffer=(char *)malloc(2*1024*1024);
	ObDataBuffer out_buffer(buffer,2*1024*1024);
	packet.set_thread_id(c->seq);
	ret=packet.serialize(out_buffer.get_data(),out_buffer.get_capacity(),out_buffer.get_position());
	ret=write_data(c->fd,out_buffer.get_data(),out_buffer.get_position());
	cout<<"报文已经达到的位置为: "<<out_buffer.get_position()<<endl;
	cout<<"服务器已经向客户端发送握手报文！"<<endl;
	return ret;
}

int CMysqlLoginer::parse_packet(easy_connection_t* c) {
	cout<<"进入parse_packet解析报文阶段！"<<endl;
	int ret;
	uint32_t packet_len=0;
	int package_header=4;
	char *buffer=(char *)malloc(2*1024*1024);
	ObDataBuffer in_buffer(buffer,2*1024*1024);
	char *len_pos=NULL;
	read_data(c->fd,in_buffer.get_data(),package_header);
	len_pos=in_buffer.get_data();
	CMysqlUtil::get_uint3(len_pos,packet_len);
	in_buffer.get_position()=package_header;
	ret=read_data(c->fd,in_buffer.get_data()+in_buffer.get_position(),packet_len);
	cout<<"packet length is: "<<packet_len<<endl;
	len_pos=in_buffer.get_data()+in_buffer.get_position();
	/*
	 * 解析登录认证报文，客户端至服务器
	 * ===================报文头===========
	 * 在此可以跳过报文头不解析，
	 * ===================报文体===========
	 * capability_flags: 客户端权能标志         4
	 * max_packet_size: 最大消息长度            4
	 * character_set: 字符编码                 1
	 * 填充值（略过）                           23
	 * user_name_: 用户名
	 * auth_response_: 挑战认证数据
	 * db_name_: 数据库名称（可选）
	 *
	 * */
    uint32_t capability_flags=0;
    uint32_t max_packet_size=0;
    uint8_t character_set=0;
    uint8_t auth_response_len=0;
    int32_t username_len=-1;
    int32_t db_len=-1;

    CMysqlUtil::get_uint4(len_pos, capability_flags);
    cout<<capability_flags<<endl;
    CMysqlUtil::get_uint4(len_pos, max_packet_size);//16MB
    cout<<max_packet_size<<endl;
	CMysqlUtil::get_uint1(len_pos, character_set);
    cout<<character_set<<endl;
	len_pos += 23;
	username_len=static_cast<int32_t>(strlen(len_pos));
	char *user_name=(char *)malloc(username_len+1);
	memcpy(user_name,len_pos,username_len);
	string user(user_name);
	cout<<"username_len: "<<username_len<<"--user name: "<<user.c_str()<<endl;
	len_pos+=username_len+1;
	CMysqlUtil::get_uint1(len_pos,auth_response_len);
	char *auth_response=(char *)malloc(static_cast<int32_t>(auth_response_len));
	memcpy(auth_response,len_pos,static_cast<int32_t>(auth_response_len));
	string auth(auth_response);
	cout<<"auth_response_len: "<<static_cast<int32_t>(auth_response_len)<<"--auth_response: "<<auth.c_str()<<endl;

	ret=0;
	return ret;
}

int CMysqlLoginer::check_privilege(easy_connection_t* c) {
	int ret;

	cout<<"验证通过，发回OK报文！"<<endl;
	CMysqlOKPacket *ok_packet=new CMysqlOKPacket();
	char *buffer=(char *)malloc(16);
	ObDataBuffer out_buffer(buffer,16);
	out_buffer.get_position()=0;
	ret=ok_packet->encode(out_buffer.get_data(),out_buffer.get_capacity(),out_buffer.get_position());
//	char *buff=new char[11];
////	char buff[12];
////	for(unsigned i=0;i<12;i++){
////		buff[i]='u';
////	}
//	buff[0]=0;
//	buff[1]=0;
//	buff[2]=10;
//	buff[3]=2;
//	buff[4]=0;
//	buff[5]=0;
//	buff[6]=0;
//	buff[7]=0;
//	buff[8]=2;
//	buff[9]=0;
//	buff[10]=0;
//	buff[11]='a';
//	buff[12]='d';
//	buff[13]='d';
//	string bb(buff);
//	cout<<"bb: "<<bb.c_str()<<"length: "<<bb.length()<<endl;
	cout<<"=================: "<<out_buffer.get_position()<<endl;
	ret=write_data(c->fd,out_buffer.get_data(),out_buffer.get_position());
	cout<<"发送数据！"<<out_buffer.get_data()<<out_buffer.get_position()<<endl;
	char *newa=(char *)malloc(out_buffer.get_position());
	memcpy(newa,out_buffer.get_data(),out_buffer.get_position());
	string sss(newa);
	cout<<"sss: "<<sss.c_str()<<endl;
	return ret;
}

void CMysqlLoginer::set_c_server(CMysqlServer *server) {
	server_=server;
}

int CMysqlLoginer::write_data(int fd,char* buffer,size_t length){
  int ret=0;
  const char* buff = buffer;
  int count = 0;
  string str(buff);
  cout<<"发送的报文内容是： "<<str.c_str()<<endl;
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

int CMysqlLoginer::read_data(int fd, char* buffer, size_t length){
	int ret = C_SUCCESS;
	static const int64_t timeout = 100000000000;

    char* buff = buffer;
    ssize_t count = 0;
    int64_t trycount = 0;
    while (C_SUCCESS == ret && length > 0 && (count = read(fd, buff, length)) != 0){
    	trycount ++;
    	if (C_SUCCESS == ret){
    		if (-1 == count){
    			if (errno == EINTR || errno == EAGAIN){
    				continue;
    			}
    			else{
    				cout<<"read data error!"<<endl;
    			}
    		}
    		buff += count;
    		length -= count;
    	}
    }
    return ret;
}
