/*
 * CMysqlHandshakePacket.cpp
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#include "c_mysql_handshake_packet.h"

CMysqlHandshakePacket::CMysqlHandshakePacket() {
    const char* str = "5.5.1";
    protocol_version_ = 10;//Protocol::HandshakeV10
    string server_version(str);
    server_version_=server_version;
    thread_id_=100;//
    memset(scramble_buff_,'a',9);
    server_capabilities_=63487;
    server_language_=8;//latin1_swedish_ci
    server_status_=0;// no this value in mysql protocol document
    memset(plugin_,0,sizeof(plugin_));
    memset(plugin2_,'b',12);
    terminated_='\0';
}

CMysqlHandshakePacket::~CMysqlHandshakePacket() {

}

void CMysqlHandshakePacket::set_thread_id(int id) {
	thread_id_=id;
}

int CMysqlHandshakePacket::serialize(char *buffer,int len,long int &pos) {
	/*------------------报文体-----------------           字节数
	 *protocol_version_: 协议版本号                         1
	 *server_version_: 服务器版本信息                        3
	 *thread_id_: 服务器线程号                              4
	 *scramble_buff_: "ob中将挑战随机数和填充值合并了"         9
	 *server_capabilities_: 服务器权能标志                   2
	 *server_language_: 字符编码                           1
	 *server_status_: 服务器状态                            2
    *char plugin_[13]: "ob中服务器权能，挑战长度和填充值的和"  13
    *char plugin2_[12]: 第二波挑战随机数，至少12字节         12
	 *terminated_: 结束                                   1
	 *------------------报文头-----------------
	 *下面是要放到报文头中
	 *(header size)pkt_len: 消息长度				          3
	 *(header seq)0： 消息序号                              1
	 */
	string packet;
	cout<<"开始序列化报文体和报文头！"<<endl;
	//三个字节的 length=48;
	//一个字节的 seq=0;



}
