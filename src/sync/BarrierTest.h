/*
 * BarrierTest.h
 *
 *      Author: casa
 */

#ifndef BARRIERTEST_H_
#define BARRIERTEST_H_

#include "Barrier.h"

#include <iostream>
#include <vector>
using namespace std;

#include <pthread.h>

class BarrierTest {
public:
	BarrierTest(int nThreads);
	virtual ~BarrierTest();

	/*添加一个func，也是在添加一个线程*/
	void funcAdd();
	/*初始化barrier，这个barrier中含有三个线程*/
	void init();
	/* 静态函数调用成员变量，要传this指针
	 * 静态函数被调用可以直接进行
	 * */
	static void * func(void *args);

private:
	Barrier *barrier;
	int nThreads;

public:
	vector<pthread_t> ps;
};
#endif /* BARRIERTEST_H_ */
