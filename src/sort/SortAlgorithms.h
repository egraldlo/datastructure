/*
 * SortAlgorithms.h
 *
 *  Created on: 2014-5-11
 *      Author: casa
 */

#ifndef SORTALGORITHMS_H_
#define SORTALGORITHMS_H_

#include <iostream>
using namespace std;

#include "../../Log.h"
#include "../../Debug.h"

#include "../sec/Try.h"

//这里两点值得优化：
//1. 不只是int
//2. 支持从本地读文件
static int waitingforSort[20]={3,5,8,4,23,52,56,13,544,65,3454,41,43,1,314,546,75,74,12,9};

//在此每个排序算法为SortAlgorithms类的一个成员函数
class SortAlgorithms {
public:
	SortAlgorithms();
	virtual ~SortAlgorithms();

public:
	void init(){
		cout<<"number: "<<NUMBER<<endl;
		Log *lg=new Log();
		lg->logging();
		Try *t=new Try();
		t->test();
		cout<<"初始化待排序数组！"<<endl;
	};

	void test(){
		cout<<"cdcdcdcdc"<<endl;
	}
public:
	void quickSort();
	void mergeSort();
	void radixSort();

};

#endif /* SORTALGORITHMS_H_ */
