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

int CMysqlServer::start() {
	cout<<"启动cliams mysql server..."<<endl;
	int ret;
	int rc;
	easy_listen_t* listen = NULL;

	eio_=easy_eio_create(eio_,io_threads_count_);
    eio_->do_signal = 0;
    //OB_CONNECTION_FREE_TIME_S的时间
    eio_->force_destroy_second = 900;
    eio_->checkdrc = 1;
    eio_->support_ipv6 = 0;
    eio_->no_redispatch = 1;
    easy_eio_set_uthread_start(eio_, easy_on_ioth_start, this);
    eio_->uthread_enable = 0;
	command_queue_thread_.init();
	eio_->tcp_defer_accept = 0;

	ret=initialize();
	cout<<"initialize()返回为： "<<ret<<endl;

    if(NULL==(listen=easy_connection_add_listen(eio_, NULL, port_, &handler_))){
    	cout<<"启动监听错误！"<<endl;
    }else{
    	cout<<"监听已经启动，端口号为"<<port_<<endl;
    }

    rc = easy_eio_start(eio_);

    //这里的原先为EASY_OK == rc,先假设EASY_OK是0
    if(0==rc){
    	cout<<"启动成功！"<<endl;
    }
    else{
    	cout<<"启动失败！"<<endl;
    }

    //是否需要等待？
    if(0==ret){
        easy_eio_wait(eio_);
    }
}

int CMysqlServer::initialize() {
	cout<<"初始化服务器！"<<endl;
	//为什么OB在此是没有初始化日志服务器的呢？
	login_hander_=new CMysqlLoginer();
    memset(&handler_, 0, sizeof(easy_io_handler_pt));
    //ObMySQLCallback这个类要我么来实现，回调类
    handler_.encode=CMysqlCallback::encode;//ObMySQLCallback::encode;
    handler_.decode=CMysqlCallback::decode;//ObMySQLCallback::decode;
    handler_.process=CMysqlCallback::process;//ObMySQLCallback::process;
    handler_.get_packet_id=CMysqlCallback::get_packet_id;//ObMySQLCallback::get_packet_id;
    handler_.on_disconnect=CMysqlCallback::on_disconnect;//ObMySQLCallback::on_disconnect;
    //on_connect函数有一个监听的方法，这个监听的方法在监听登录的用户
    handler_.on_connect=CMysqlCallback::on_connect;//ObMySQLCallback::on_connect;
    handler_.cleanup=CMysqlCallback::clean_up;//ObMySQLCallback::clean_up;
    handler_.user_data=this;

    //这里要封装成函数
    io_threads_count_=2;
    port_=2345;

    return 0;
}

void CMysqlServer::on_ioth_start() {
  //配置文件传值
  int affinity_start_cpu=1;
  int affinity_end_cpu=2;
  //检查传值是否正确
  if (0<=affinity_start_cpu&& affinity_start_cpu<= affinity_end_cpu){
    static volatile int cpu = 0;
    //下面这个函数是否在标准库中？
    int local_cpu=__sync_fetch_and_add(&cpu, 1) % (affinity_end_cpu - affinity_start_cpu + 1) + affinity_start_cpu;
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(local_cpu, &cpuset);
    int ret = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
  }
}

int CMysqlServer::login_handler(easy_connection_t * c) {
	cout<<"登录处理"<<endl;
	login_hander_->set_c_server(this);
	int ret;
	ret=login_hander_->login(c);
	return ret;
}
