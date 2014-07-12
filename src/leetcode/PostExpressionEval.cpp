/*
 * PostExpressionEval.cpp
 *
 *  Created on: 2014-7-12
 *      Author: casa
 */

#include "PostExpressionEval.h"

PostExpressionEval::PostExpressionEval() {
	// TODO 自动生成的构造函数存根

}

PostExpressionEval::~PostExpressionEval() {
	// TODO 自动生成的析构函数存根
}

int PostExpressionEval::evalRPN(vector<string> tokens){
	int ret;
	for(int i=0;i<tokens.size();i++){
		string op=tokens[i];
		if(!isOperator(op)){
			numericStack.push(atoi(tokens[i].c_str()));
			cout<<atoi(tokens[i].c_str())<<endl;
		}
		else{
			int first=numericStack.top();numericStack.pop();
			int second=numericStack.top();numericStack.pop();
			int result=cal(second, first, op);
			numericStack.push(result);
		}
	}
	ret=numericStack.top();
	return ret;
}

bool PostExpressionEval::isOperator(string item){
	if(item=="+")
		return true;
	else if(item=="-")
		return true;
	else if(item=="/")
		return true;
	else if(item=="*")
		return true;
	else
		return false;
}

int PostExpressionEval::cal(int left, int right, string op){
	int res;
	if(op=="+")
		return left+right;
	else if(op=="-")
		return left-right;
	else if(op=="*")
		return left*right;
	else
		return left/right;
	return res;
}
