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

public:
	void start();
};

#endif /* LEE_H_ */
