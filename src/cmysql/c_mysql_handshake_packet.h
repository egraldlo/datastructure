/*
 * CMysqlHandshakePacket.h
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#ifndef C_MYSQL_HANDSHAKE_PACKET_H_
#define C_MYSQL_HANDSHAKE_PACKET_H_

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
	int thread_id_;//connection id
};

#endif /* CMYSQLHANDSHAKEPACKET_H_ */
