/*
 * CMysqlServer.cpp
 *
 *  Created on: 2014-5-19
 *      Author: casa
 */

#include "c_mysql_server.h"

CMysqlServer::CMysqlServer() {

}

CMysqlServer::~CMysqlServer() {

}

void CMysqlServer::start() {
	cout<<"启动cliams mysql server..."<<endl;
	command_queue_thread_.init();
}

void CMysqlServer::initialize() {

}
