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

class Try {
public:
	Try();
	void print(){
		cout<<"in the print!"<<endl;
	}
	virtual ~Try();
};

#endif /* TRY_H_ */
