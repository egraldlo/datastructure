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
bool SortAlgorithms::mergeSort(int array[], int tempArray[], int left, int right){
	if(left==right)
		return false;
	int middle=(left+right)/2;
	mergeSort(array,tempArray,left,middle);
	mergeSort(array,tempArray,middle+1,right);
	merge(array,tempArray,left,right,middle);
}

void SortAlgorithms::merge(int array[], int tempArray[], int left, int right, int middle){
	for(int i=left;i<=right;i++){
		tempArray[i]=array[i];
	}

	int k=left;
	int i=left;
	int j=middle+1;
	while((i<=middle)&&(j<=right)){
		if(tempArray[i]>tempArray[j]){
			array[k]=tempArray[j];
			j++;
			k++;
		}
		else{
			array[k]=tempArray[i];
			i++;
			k++;
		}
	}
	while(i<=middle){
		array[k]=tempArray[i];
		i++;
		k++;
	}
	while(j<=right){
		array[k]=tempArray[j];
		j++;
		k++;
	}
	prt(array);
}

void SortAlgorithms::radixSort(){

}

void SortAlgorithms::prt(int *arr){
	for(int i=0;i<20;i++){
		cout<<" "<<arr[i];
	}
	cout<<endl;
}
