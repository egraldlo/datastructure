/*
 * PostExpressionEval.cpp
 *
 *  Created on: 2014-7-12
 *      Author: casa
 */

#include "PostExpressionEval.h"

PostExpressionEval::PostExpressionEval() {

}

PostExpressionEval::~PostExpressionEval() {

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

InExpressionEval::InExpressionEval(){

}

InExpressionEval::~InExpressionEval(){

}

bool InExpressionEval::isPriority(string low, string upper){
	bool ret;
	if((low=="+"||low=="-") && (upper=="*"||upper=="/"))
		ret=true;
	return ret;
}

int InExpressionEval::evalRPN(vector<string> tokens){
	int ret;
	for(int i=0;i<tokens.size();i++){
		if(isOperator(tokens[i])){
			if(!operatorStack.empty()){
				string low=operatorStack.top();
				string upper=tokens[i];
				if(isPriority(low,upper)){
					operatorStack.push(tokens[i]);
				}
				else{
					/*
					 * compute
					 * */
					int left=numericStack.top();
					numericStack.pop();
					int right=numericStack.top();
					numericStack.pop();
					operatorStack.pop();
					int res=cal(left,right,low);
					numericStack.push(res);
				}
			}
			else{
				operatorStack.push(tokens[i]);
			}
		}
		else{
			numericStack.push(atoi(tokens[i].c_str()));
		}
	}
	if(!operatorStack.empty()){
		cout<<"operatorStack.size(): "<<operatorStack.size()<<endl;
		for(int j=0;j<operatorStack.size();j++){
			int left=numericStack.top();
			numericStack.pop();
			int right=numericStack.top();
			numericStack.pop();
			string op=operatorStack.top();
			operatorStack.pop();
			int res=cal(left,right,op);
			cout<<res<<endl;
			numericStack.push(res);
		}
		ret=numericStack.top();
	}
	else{
		ret=numericStack.top();
	}
	return ret;
}

bool InExpressionEval::isOperator(string item){
	if(item=="+")
		return true;
	else if(item=="-")
		return true;
	else if(item=="/")
		return true;
	else if(item=="*")
		return true;
	else if(item=="(")
		return true;
	else if(item==")")
		return true;
	else
		return false;
}

int InExpressionEval::cal(int left, int right, string op){
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
