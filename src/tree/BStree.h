/*
 * BStree.h
 *
 *  Created on: 2014-5-9
 *      Author: casa
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
using namespace std;

class BStree {
public:
	BStree();
	void info(){
		cout<<"I am in the bstree coding!"<<endl;
	}
	virtual ~BStree();
};

#endif /* BSTREE_H_ */
