/*
 * Lee.h
 *
 *  Created on: 2014-5-20
 *      Author: casa
 */

#ifndef LEE_H_
#define LEE_H_

#include "Tree/TraverseBinaryTree.h"

#include <iostream>
using namespace std;

class Lee {
public:
	Lee();
	virtual ~Lee();

	bool stringMatch(char *str1, char *str2);
	int fork_test();
	int fork_test2();
	int fork_test3();
	int pipe_test();

public:
	void start();
};

#endif /* LEE_H_ */
