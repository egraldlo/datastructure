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
#include "c_mysql_spr_packet.h"

#include <iostream>
using namespace std;

#include <pthread.h>

class CMysqlLoginer;


//send_result_set
//process_row_packets
//send_raw_packet发送最后的结果

//ObMySQLRowPacket
class CMysqlServer {
public:
	CMysqlServer();
	virtual ~CMysqlServer();

public:
    void on_ioth_start();

    int start();
	int initialize();
	int login_handler(easy_connection_t * c);
	int post_packet(easy_request_t* req, CMysqlSPRPacket* packet, uint8_t seq);

    static void easy_on_ioth_start(void *arg){
      if (arg != NULL){
        CMysqlServer *server = reinterpret_cast<CMysqlServer*>(arg);
        server->on_ioth_start();
      }
    }

    inline void init_easy_buf(easy_buf_t *buf, char* data, easy_request_t *req, uint64_t size)
    {
      if (NULL != buf && NULL != data)
      {
        buf->pos = data;
        buf->last = buf->pos;
        buf->end = buf->last + size;
        buf->cleanup = NULL;
        if (NULL != req && NULL != req->ms)
        {
          buf->args = req->ms->pool;
        }
        buf->flags = 0;
        easy_list_init(&buf->node);
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
