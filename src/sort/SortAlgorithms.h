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

//这里两点值得优化：
//1. 不只是int
//2. 支持从本地读文件
static int waitingforSort[20]={3,5,8,4,23,52,56,13,544,65,3454,41,43,1,314,546,75,74,12,9};

//在此每个排序算法为SortAlgorithms类的一个成员函数
class SortAlgorithms {
public:
	SortAlgorithms();
	virtual ~SortAlgorithms();

	int selectPivot(int start, int end);
	void swap(int&,int&);
	int partition(int data[], int start, int end);

	void merge(int array[], int tempArray[], int left, int right, int middle);



	void bubleSort(int array[],int size);
	void selectSort(int array[],int size);
	void insertSort(int array[],int size);
	void heapSort(int array[],int size);

	bool quickSort(int data[], int start, int end);
	bool mergeSort(int array[], int tempArray[], int left, int right);
//	void shellSort(){};
	void radixSort();

	void prt(int *arr);
};

#endif /* SORTALGORITHMS_H_ */
