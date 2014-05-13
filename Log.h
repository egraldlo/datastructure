/*
 * Log.h
 *
 *  Created on: 2014-5-13
 *      Author: casa
 */

#ifndef LOG_H_
#define LOG_H_

#include <iostream>
using namespace std;

class Log {
public:
	Log();
	virtual ~Log();

public:
	void logging(){
		cout<<"in the logging!!!"<<endl;
	}
};

#endif /* LOG_H_ */
