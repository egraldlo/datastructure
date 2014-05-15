/*
 * A1.h
 *
 *  Created on: 2014-5-15
 *      Author: casa
 */

#ifndef A1_H_
#define A1_H_

#include "../b/B.h"

class A1 {
public:
	A1();
	virtual ~A1();

public:
	void test(){
		B *b=new B();
	}
};

#endif /* A1_H_ */
