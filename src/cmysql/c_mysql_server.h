/*
 * CMysqlServer.h
 *
 *  Created on: 2014-5-19
 *      Author: casa
 */

#ifndef C_MYSQL_SERVER_H_
#define C_MYSQL_SERVER_H_

#include "c_mysql_command_queue_thread.h"

#include <iostream>
using namespace std;

class CMysqlServer {
public:
	CMysqlServer();
	virtual ~CMysqlServer();

public:
	void start();
	void initialize();

private:
	CMysqlCommandQueueThread command_queue_thread_;
};

#endif /* CMYSQLSERVER_H_ */
