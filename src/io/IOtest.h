/*
 * IOtest.h
 *
 *  Created on: 2014-8-7
 *      Author: casa
 */

#ifndef IOTEST_H_
#define IOTEST_H_

#include <iostream>
using namespace std;

class IOtest {
public:
	IOtest();
	virtual ~IOtest();

	void init();
	void nonblocking();

private:

};

#endif /* IOTEST_H_ */
