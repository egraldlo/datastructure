/*
 * CMysqlServer.h
 *
 *  Created on: 2014-5-19
 *      Author: casa
 */

#ifndef C_MYSQL_SERVER_H_
#define C_MYSQL_SERVER_H_

#include "easy_io.h"
#include "easy_io_struct.h"

#include "c_mysql_command_queue_thread.h"
#include "c_mysql_callback.h"
#include "c_mysql_loginer.h"

#include <iostream>
using namespace std;

#include <pthread.h>

class CMysqlServer {
public:
	CMysqlServer();
	virtual ~CMysqlServer();

public:
	int start();
	int initialize();
	int login_handler(easy_connection_t * c);

public:
    void on_ioth_start();
    static void easy_on_ioth_start(void *arg){
      if (arg != NULL){
        CMysqlServer *server = reinterpret_cast<CMysqlServer*>(arg);
        server->on_ioth_start();
      }
    }


private:
	CMysqlCommandQueueThread command_queue_thread_;
	int io_threads_count_;
	int port_;

    easy_io_t* eio_;
    easy_io_handler_pt handler_;

    CMysqlLoginer *login_hander_;
};

#endif /* CMYSQLSERVER_H_ */
