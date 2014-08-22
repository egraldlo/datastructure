/*
 * IOtest.cpp
 *
 *  Created on: 2014-8-7
 *      Author: casa
 */

#include "IOtest.h"
#include <fcntl.h>

IOtest::IOtest() {
	// TODO 自动生成的构造函数存根

}

IOtest::~IOtest() {
	// TODO 自动生成的析构函数存根
}

void IOtest::init(){
	cout<<"this is the io test!"<<endl;
}

void IOtest::nonblocking(){
	int ntowrite,nwrite,erron;
	char *ptr;

	char buf[50000];

	nwrite=read(STDIN_FILENO,buf,sizeof(buf));
//	fcntl(STDOUT_FILENO,O_NONBLOCK);

	ptr=buf;
	while(nwrite>0){
		erron=0;
		nwrite=write(STDOUT_FILENO,ptr,nwrite);
		cout<<"error message: "<<nwrite<<endl;

		if(nwrite>0){
			ptr+=nwrite;
			nwrite-=nwrite;
		}
	}

//	fcntl(STDOUT_FILENO,O_NONBLOCK);
}
