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
	else if(low=="(")
		return true;
	else
		ret=false;
	return ret;
}

int InExpressionEval::evalRPN(vector<string> tokens){
	int ret;
	for(int i=0;i<tokens.size();i++){
		if(isOperator(tokens[i])){
			if(tokens[i]=="("){
				operatorStack.push(tokens[i]);
				cout<<"when '(', into stack!"<<endl;
				continue;
			}
			if(!operatorStack.empty()){
				string low=operatorStack.top();
				if(low==")"){
					operatorStack.pop();
					low=operatorStack.top();
					if(low=="("){
						operatorStack.pop();
						low=operatorStack.top();
					}
					else{
						low=operatorStack.top();
						operatorStack.pop();
					}
				}
				string upper=tokens[i];
				if(upper==")"){
					int right=numericStack.top();
					numericStack.pop();
					int left=numericStack.top();
					numericStack.pop();
					string op=operatorStack.top();
					operatorStack.pop();
					int res=cal(left,right,op);
					cout<<"when ')', cal "<<left<<op.c_str()<<right<<"="<<res<<" into stack"<<res<<endl;
					numericStack.push(res);
					operatorStack.pop();
					operatorStack.push(")");
				}
				else if(isPriority(low,upper)){
					operatorStack.push(upper);
					cout<<"when priority issue, into stack "<<upper.c_str()<<endl;
				}
				else{
					/*
					 * compute
					 * */
					int right=numericStack.top();
					numericStack.pop();
					int left=numericStack.top();
					numericStack.pop();
					operatorStack.pop();
					int res=cal(left,right,low);
					cout<<"cal "<<left<<low.c_str()<<right<<"="<<res<<"into stack"<<endl;
					numericStack.push(res);
					operatorStack.push(upper);
				}
			}
			else{
				operatorStack.push(tokens[i]);
				cout<<"at first, into stack "<<tokens[i].c_str()<<endl;
			}
		}
		else{
			numericStack.push(atoi(tokens[i].c_str()));
			cout<<"into stack a number:"<<atoi(tokens[i].c_str())<<endl;
		}
	}
	if(!operatorStack.empty()){
		cout<<"operatorStack.size(): "<<operatorStack.size()<<endl;
		int size=operatorStack.size();
		for(int k=0;k<size;k++){
			string cc=operatorStack.top();
			operatorStack.pop();
			cout<<cc.c_str()<<endl;
		}
		for(int j=0;j<size;j++){
			int right=numericStack.top();
			numericStack.pop();
			int left=numericStack.top();
			numericStack.pop();
			string op=operatorStack.top();
			if(op==")"){
				operatorStack.pop();
				op=operatorStack.top();
				if(op=="("){
					operatorStack.pop();
					op=operatorStack.top();
					operatorStack.pop();
				}
				else{
					op=operatorStack.top();
					operatorStack.pop();
					operatorStack.pop();
				}
			}
			int res=cal(left,right,op);
			cout<<"op: "<<op.c_str()<<res<<endl;
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
