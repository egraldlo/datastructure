/*
 * ArrayAlgos.h
 *
 *  Created on: 2014-7-31
 *      Author: casa
 */

#ifndef ARRAYALGOS_H_
#define ARRAYALGOS_H_

#include <iostream>
using namespace std;

class ArrayAlgos {
public:
	ArrayAlgos();
	virtual ~ArrayAlgos();

public:
	void msort();
	void merge(int A[],int m,int B[],int n);
};

#endif /* ARRAYALGOS_H_ */
