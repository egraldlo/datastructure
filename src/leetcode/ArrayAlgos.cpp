/*
 * ArrayAlgos.cpp
 *
 *  Created on: 2014-7-31
 *      Author: casa
 */

#include "ArrayAlgos.h"

ArrayAlgos::ArrayAlgos() {
	// TODO 自动生成的构造函数存根

}

ArrayAlgos::~ArrayAlgos() {
	// TODO 自动生成的析构函数存根
}

void ArrayAlgos::msort(){

}

void ArrayAlgos::merge(int A[],int m,int B[],int n){
	for(int i=m;i>0;i--){
		A[i+n-1]=A[i-1];
		cout<<"A[i+n-1]=A[i]: "<<A[i+n-1]<<"="<<A[i]<<endl;
	}
	int k=0,l=0,h=0;
	while(k<m&&l<n){
		if(A[k+n]<B[l]){
			A[h]=A[k+n];
			cout<<"h: "<<k+n<<": "<<A[h]<<endl;
			h++;
			k++;
		}
		else{
			A[h]=B[l];
			h++;
			l++;
		}
	}
	while(k<m){
		A[h]=A[k+n];
		h++;
		k++;
	}
	while(l<n){
		A[h]=B[l];
		h++;
		l++;
	}
	for(int i=0;i<2;i++){
		cout<<A[i]<<endl;
	}
}
