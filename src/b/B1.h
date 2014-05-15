/*
 * B1.h
 *
 *  Created on: 2014-5-15
 *      Author: casa
 */

#ifndef B1_H_
#define B1_H_

#include "../a/A.h"

class B1 {
public:
	B1();
	virtual ~B1();

public:
	void test(){
		A *a=new A();
	}
};

#endif /* B1_H_ */
