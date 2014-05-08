/*
 * Barrier.h
 *
 *      Author: casa
 */

#ifndef BARRIER_H_
#define BARRIER_H_

#include <iostream>
using namespace std;

#include <pthread.h>
#include <stdio.h>

class Barrier {
public:
	Barrier(int nThreads);
	virtual ~Barrier();

	void Arrive();

private:
	/*线程个数*/
	int             m_nThreads;
	/*互斥量*/
	pthread_mutex_t m_l_SyncLock;
	/*条件变量，用条件变量的意义是，当达到线程个数这个条件时barrier打开*/
	pthread_cond_t  m_cv_SyncCV;
	/*当前线程计数*/
	volatile int    m_nSyncCount;
};

#endif /* BARRIER_H_ */
