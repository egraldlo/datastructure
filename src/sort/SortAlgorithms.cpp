/*
 * SortAlgorithms.cpp
 *
 *  Created on: 2014-5-11
 *      Author: casa
 */

#include "SortAlgorithms.h"
#include "/usr/include/stdio.h"

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
	int last=start;
	int pivot=data[start];
	for(int i=start+1;i<=end;i++) {
		if(data[i]<pivot){
			last++;
			swap(data[i],data[last]);
		}
	}
	swap(data[start],data[last]);
	if(last-start>1)
		quickSort(data,start,last-1);
	if(end-start>1)
		quickSort(data,last+1,end);
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

void SortAlgorithms::bubleSort(int array[], int n){
	cout<<"冒泡排序的时间复杂度是：n2  稳定 冒泡排序的思想是将较大的放在后面，第一遍遍历完了之后，最后一个元素最大"<<endl;
	int temp=0;
	bool flag=false;
	for(unsigned j=0;j<n;j++){
		flag=true;
		//这里是n-j-1而不是n-j，因为array[i+1]可能会溢出
		for(unsigned i=0;i<n-j-1;i++){
			if(array[i]>array[i+1]){
				temp=array[i];
				array[i]=array[i+1];
				array[i+1]=temp;
				flag=false;//如果一次交换都没有，证明都是有序的，就不需要继续下去
			}
		}
		if(flag)
			break;
	}
}

//	int temp;
//	for(int i=1;i<n;i++){
//		temp=array[i];
//		//比较从0<=到<=i-1
//		int j=i-1;
//		while(j>=0){
//			if(temp<array[j])
//				array[j+1]=array[j];
//			j--;
//		}
//		array[j+1]=temp;
//	}

void SortAlgorithms::selectSort(int array[], int n){
	cout<<"选择排序的时间复杂度是：n2  不稳定 选择排序的思想是选择一个最小的放在已排序的末尾"<<endl;
//	int temp=0;
//	int max=0;
//	int t;
//	for(unsigned i=0;i<n;i++){
//		max=array[i];
//		temp=i;
//		for(unsigned j=i;j<n;j++)
//			if(max<array[j]){
//				max=array[j];
//				temp=j;
//			}
//		t=array[temp];
//		array[temp]=array[i];
//		array[i]=t;
//	}      //这里注释的是我的开始的写法，很挫，然后我的改进方法如下：
	int max=0;
	int i=0;
	int j=0;
	int temp=0;
	for(i=0;i<n-1;i++){
		max=i;
		for(j=i+1;j<n;j++){
			if(array[max]<array[j])
				max=j;
		}
		temp=array[max];
		array[max]=array[i];
		array[i]=temp;
	}
}

void SortAlgorithms::insertSort(int array[], int n){
	cout<<"插入排序的时间复杂度是：n2  稳定 插入排序的思想是将后面的放在已排序中"<<endl;
	int curse=0;
	int curse1;
	printf("%p\n",&curse);
	printf("%p\n",&curse1);
	cout<<": "<<curse<<endl;
	cout<<": "<<curse1<<endl;
//	int i=0;
	for(int i=1;i<n;i++){
		curse=array[i];
		//i-1----0
		int temp=i-1;
		while(temp>=0){
			if(curse>array[temp]){
				break;
			}
			temp--;
		}

		//i->temp+1
		int temp2=i;
		while(temp2>temp+1){
			array[temp2]=array[temp2-1];
			temp2--;
		}
		//放在temp+1的位置上
		array[temp+1]=curse;
	}
}

void heaplify(int array[], int i, int len) {
	int child=i*2+1;
	while(child<len) {
		if(child+1<len && array[child]<array[child+1])
			child++;
		if(array[i]>array[child])
			break;
		else {
			int temp=array[i];
			array[i]=array[child];
			array[child]=temp;

			i=child;
			child=i*2+1;
		}
	}
}

void SortAlgorithms::heapSort(int array[], int n) {
	//initialize the heap
	for(int i=(n-2)/2;i>=0;i--) {
		heaplify(array,i,n);
	}

	for(int i=0;i<n;i++) {
		int temp=array[0];
		array[0]=array[n-i-1];
		array[n-i-1]=temp;

		heaplify(array,0,n-i-1);
	}
}


//void sift(int d[], int ind, int len){
//	int i = ind;
//	int c = i * 2 + 1;
//
//	while(c < len)
//	{
//		if(c + 1 < len && d[c] < d[c + 1])
//			c++;
//		if(d[i] > d[c]) break;
//		else
//		{
//			int t = d[c];
//			d[c] = d[i];
//			d[i] = t;
//			i = c;
//			c = 2 * i + 1;
//		}
//	}
//
//	return;
//}
//
//void SortAlgorithms::heapSort(int array[], int n){
//	for(int i = (n - 2) / 2; i >= 0; i--)
//		sift(array, i, n);
//
//	for(int j = 0; j < n; j++)
//	{
//		int t = array[0];
//		array[0] = array[n - j - 1];
//		array[n - j - 1] = t;
//
//		sift(array, 0, n - j - 1);
//
//	}
//}

void SortAlgorithms::prt(int *arr){
	for(int i=0;i<20;i++){
		cout<<" "<<arr[i];
	}
	cout<<endl;
}
