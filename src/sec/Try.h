/*
 * Try.h
 *
 *  Created on: 2014-5-8
 *      Author: casa
 */

#ifndef TRY_H_
#define TRY_H_

#include "thir/Try1.h"

#include <iostream>
using namespace std;

class Try {
public:
	Try();
	void print(){
		Try1 *t1=new Try1();
		t1->print();
		cout<<"in the print!"<<endl;
	}
	virtual ~Try();
};

#endif /* TRY_H_ */
