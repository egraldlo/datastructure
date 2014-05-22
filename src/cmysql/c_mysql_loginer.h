/*
 * CMysqlLoginer.h
 *
 *  Created on: 2014-5-22
 *      Author: casa
 */

#ifndef C_MYSQL_LOGINER_H_
#define C_MYSQL_LOGINER_H_

#include "easy_io.h"

class CMysqlServer;

class CMysqlLoginer {
public:
	CMysqlLoginer();
	virtual ~CMysqlLoginer();

public:
	int login(easy_connection_t* c);
	int handshake(easy_connection_t* c);
	int parse_packet(easy_connection_t* c);
	int check_privilege(easy_connection_t* c);

	void set_c_server(CMysqlServer *server);

private:
	CMysqlServer *server_;
};

#endif /* CMYSQLLOGINER_H_ */
