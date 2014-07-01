/*
 * CMysqlSQLPacket.h
 *
 *  Created on: 2014-7-1
 *      Author: casa
 */

#ifndef C_MYSQL_SQL_PACKET_H_
#define C_MYSQL_SQL_PACKET_H_

#include <iostream>
using namespace std;

class CMysqlSQLPacket {
public:
	CMysqlSQLPacket();
	virtual ~CMysqlSQLPacket();

	void encode();
};

#endif /* CMYSQLSQLPACKET_H_ */
