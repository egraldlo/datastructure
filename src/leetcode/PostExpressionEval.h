/*
 * PostExpressionEval.h
 *
 *  Created on: 2014-7-12
 *      Author: casa
 */

#ifndef POSTEXPRESSIONEVAL_H_
#define POSTEXPRESSIONEVAL_H_

#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <stdlib.h>
#include <sstream>

class PostExpressionEval {
public:
	PostExpressionEval();
	virtual ~PostExpressionEval();

	int evalRPN(vector<string> );
	bool isOperator(string);
	int cal(int, int, string);

private:
	stack<string> operatorStack;
	stack<int> numericStack;
};

class InExpressionEval {
public:
	InExpressionEval();
	virtual ~InExpressionEval();

	bool isPriority(string, string);
	int evalRPN(vector<string> );
	bool isOperator(string);
	int cal(int, int, string);

private:
	stack<string> operatorStack;
	stack<int> numericStack;
};

#endif /* POSTEXPRESSIONEVAL_H_ */
