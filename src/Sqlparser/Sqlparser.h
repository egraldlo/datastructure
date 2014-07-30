/*
 * Sqlparser.h
 *
 *  Created on: 2014-7-30
 *      Author: casa
 */

#ifndef SQLPARSER_H_
#define SQLPARSER_H_

#include <iostream>
using namespace std;

struct LogicalPlan{
	int plan;
};

/*
 * this class will use get the string which users enter, and parse the
 * string into parse tree which consists of logical operators.
 * */
class Sqlparser {
public:
	Sqlparser();
	virtual ~Sqlparser();

	/* todo: turn the tree into a logical operator tree, and
	 * we must get a logical operator *.
	 *  */
	LogicalPlan* parse(){
		return 0;
	};

	void init(){
		cout<<"In the sql parser!"<<endl;
	}
};

#endif /* SQLPARSER_H_ */
