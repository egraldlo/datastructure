/*
 * SortAlgorithms.cpp
 *
 *  Created on: 2014-5-11
 *      Author: casa
 */

#include "SortAlgorithms.h"

SortAlgorithms::SortAlgorithms() {

}

SortAlgorithms::~SortAlgorithms() {

}

int SortAlgorithms::selectPivot(int start, int end){
	return (start+end)/2;
}

void SortAlgorithms::swap(int &a, int &b) {
	int temp;
	temp=a;
	a=b;
	b=temp;
}

/* 分而治之
 * 选轴值
 * 快速排序算法不稳定
 * 非递归
 * */
void SortAlgorithms::quickSort(int data[], int start, int end) {
	cout<<"in the quick sort!"<<endl;
	/*
	 * analysis on quick sort!
	 * */
	int pivot=selectPivot(start,end);
	swap(data[pivot],data[end]);
	pivot=partition(data,start,end);
	quickSort(data,start,pivot-1);
	quickSort(data,pivot+1,end);
}

int SortAlgorithms::partition(int data[], int start, int end){
	int rt;
	int temp=data[end];
	int i=start;
	int j=end-1;

	while(i<j){
		while(data[i]<=temp)
			i++;
		swap(data[i],temp);

		while(data[j]>temp)
			j--;
		swap(data[j],temp);
		i++;
	}
	rt=i;
	return rt;
}

/* 归并排序的空闲消耗比较大 */
void SortAlgorithms::mergeSort(){

}

void SortAlgorithms::radixSort(){

}

void SortAlgorithms::prt(){
	for(int i=0;i<20;i++){
		cout<<" "<<waitingforSort[i];
	}
	cout<<endl;
}
