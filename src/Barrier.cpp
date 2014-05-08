/*
 * Barrier.cpp
 *
 *      Author: casa
 */

#include "Barrier.h"

Barrier::Barrier(int nThreads) {
	m_nThreads = nThreads;
	int ret;
	ret = pthread_mutex_init(&m_l_SyncLock, NULL);
	if(ret!=0)
		printf("初始化互斥量失败!\n");
	printf("初始化barrier，所有的线程到达barrier才打开!\n");
	ret = pthread_cond_init(&m_cv_SyncCV, NULL);
	if(ret!=0)
		printf("初始化条件变量失败!\n");
	m_nSyncCount = 0;
}

Barrier::~Barrier() {
	  pthread_mutex_destroy(&m_l_SyncLock);
	  pthread_cond_destroy(&m_cv_SyncCV);
}

void Barrier::Arrive() {
	pthread_mutex_lock(&m_l_SyncLock);
	m_nSyncCount++;
	if(m_nSyncCount == m_nThreads) {
		printf("最后一个线程到达，开始broadcast!\n");
		pthread_cond_broadcast(&m_cv_SyncCV);
		m_nSyncCount = 0;
	}
	else {
		cout<<"等待达到线程个数以致栅栏打开!"<<endl;
		pthread_cond_wait(&m_cv_SyncCV, &m_l_SyncLock);
	}
	pthread_mutex_unlock(&m_l_SyncLock);
}
