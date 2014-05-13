/*
 * Thir.h
 *
 *  Created on: 2014-5-13
 *      Author: casa
 */

#ifndef THIR_H_
#define THIR_H_

#include <iostream>
using namespace std;

class Thir {
public:
	Thir();
	virtual ~Thir();

public:
	void test(){
		cout<<"in the third level!!!"<<endl;
	};
};

#endif /* THIR_H_ */
