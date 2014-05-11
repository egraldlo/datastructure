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

//在此每个排序算法为SortAlgorithms类的一个成员函数
class SortAlgorithms {
public:
	SortAlgorithms();
	virtual ~SortAlgorithms();

public:
	void test(){
		cout<<"In the test!"<<endl;
	}

public:
	void quickSort();
	void mergeSort();
};

#endif /* SORTALGORITHMS_H_ */
