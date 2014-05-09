/*
 * BarrierTest.cpp
 *
 *      Author: casa
 */

#include "BarrierTest.h"

BarrierTest::BarrierTest(int nThreads)
:nThreads(nThreads){

}

BarrierTest::~BarrierTest() {

}

void * BarrierTest::func(void *args){
	/*静态函数调用成员变量通过this指针*/
	BarrierTest *bt=(BarrierTest *)(args);
	bt->barrier->Arrive();
	return (void *)(0);
}

void BarrierTest::funcAdd(){
	pthread_t p1;
	pthread_create(&p1,NULL,func,this);
	cout<<"创建线程： "<<p1<<endl;
	ps.push_back(p1);
}

void BarrierTest::init(){
	/*这里的barrier是含有三个线程到达即可以pass过barrier的*/
	barrier=new Barrier(nThreads);
}
