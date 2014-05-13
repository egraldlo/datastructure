/*
 * Try.h
 *
 *  Created on: 2014-5-8
 *      Author: casa
 */

#ifndef TRY_H_
#define TRY_H_

#include <iostream>
using namespace std;

#include "../external/ClaimsHDFS.h"
#include "thir/Thir.h"

class Try {
public:
	Try();
	void print(){
		cout<<"in the print!"<<endl;
		Thir *tr=new Thir();
		tr->test();
	}

	void test(){
		cout<<"in thr try test"<<endl;
	}
	virtual ~Try();
};

#endif /* TRY_H_ */
