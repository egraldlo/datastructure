/*
 * B.h
 *
 *  Created on: 2014-5-15
 *      Author: casa
 */

#ifndef B_H_
#define B_H_

#include "../a/A.h"
#include <iostream>
using namespace std;

class B:public A {
public:
	B():A(){};
	virtual ~B(){};
	void tes(){
		cout<<"hello In B class!"<<endl;
	}
};

#endif /* B_H_ */
