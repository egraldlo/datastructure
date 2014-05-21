/*
 * expression.cpp
 *
 *  Created on: 2014-5-21
 *      Author: casa
 */

#include "expression.h"

expression::expression(vector<expression_elem> expr)
:expression_(expr) {

}

expression::~expression() {

}

expression_elem expression::calculate(stack<expression_elem> &expression_stack) {
	expression_elem ret;

	return ret;
}

stack<expression_elem> expression::transform() {
	stack<expression_elem> ret;
	stack<expression_elem> operators_stack;
	for(unsigned i=0;i<expression_.size();i++){

	}
	return ret;
}
