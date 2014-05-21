/*
 * expression.h
 *
 *  Created on: 2014-5-21
 *      Author: casa
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_
/*后缀表达式：运算符放在运算对象的后面，所有的计算按照运算符出现的
 *顺序，严格从坐向右进行，不考虑运算符的优先规则，因此没有括号了
 *例如：( 2 + 1 ) * 3  -->  2 1 + 3 *
 *本程序也是输入这样的一个表达式( 2 + 1 ) * 3，然后转化为后缀表达式计算出结果
 */
#include <vector>
#include <stack>
using namespace std;

class expression_elem{
public:
	enum elem_type{tvalue,toperator};
public:
	expression_elem(){}
	~expression_elem(){}

private:
	union{
		int _int;
		float _float;
	}value;
	elem_type type;
};

class expression {
public:
	expression(vector<expression_elem> expr);
	virtual ~expression();

public:
	/*
	 * 计算分两步，转化和求值：
	 * 转化为中缀表达式转化为后缀表达式
	 * 求职为对后缀表达式求值
	 * */
	expression_elem calculate(stack<expression_elem> &expression_stack);
	stack<expression_elem> transform();

private:
	vector<expression_elem> expression_;
};

#endif /* EXPRESSION_H_ */
