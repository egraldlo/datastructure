/*
 * CMysqlHandshakePacket.h
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#ifndef C_MYSQL_HANDSHAKE_PACKET_H_
#define C_MYSQL_HANDSHAKE_PACKET_H_

#include <string>
#include <iostream>
using namespace std;

class CMysqlHandshakePacket {
public:
	CMysqlHandshakePacket();
	virtual ~CMysqlHandshakePacket();

public:
	void set_thread_id(int id);
	int serialize(char *buffer,int len,long int &pos);

private:
    uint8_t protocol_version_;
    string server_version_;
    int thread_id_;//connection id
    char scramble_buff_[8];// auth_plugin_data_part_1 : first 8 bytes of the auth-plugin data
    int server_capabilities_;  /* set value to use 4.1protocol */
    int server_language_;
    int server_status_;
    char plugin_[13];        /* always 0x00 */
    char plugin2_[12];
    char terminated_;
    string str_buf_;   //store ObString content



};

#endif /* CMYSQLHANDSHAKEPACKET_H_ */
