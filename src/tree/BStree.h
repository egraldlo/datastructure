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

#include "../sort/SortAlgorithms.h"

/*
 * 二叉树性质（二叉搜索树）：
 * 1，若节点的左子树不空，左子树中所有节点值均小于根节点
 * 2，若节点的右子树不空，右子树中所有节点值均大于根节点
 * 3，左右子树都是二叉树
 * 4，没有键值相等的节点
 * */

template <class Value>
class BStree {
public:
	//在此是相当于两个数据结构，外部数据结构和类是不一样的模板参数
	template <typename V>
	struct node{
		V value;
		node * left;
		node * right;
	};

public:
	BStree():root(0){
		cout<<"用特定的数据类型构造了空树！"<<endl;
	};

	virtual ~BStree(){};

public:
	void Insert(Value value);
	void Delete(Value value);
	void Display();

private:
	node<Value> * root;
};

//C++编译器不支持对模板的分离式编译，将成员函数的实现放在.h文件中
template <typename Value>
void BStree<Value>::
Insert(Value value){
	cout<<"向树中插入一个值！"<<value<<endl;
}

template <typename Value>
void BStree<Value>::
Delete(Value value){
	cout<<"删除树中的某个值！"<<value<<endl;
}

template <typename Value>
void BStree<Value>::
Display(){
	cout<<"输出这棵树上所有的值！"<<endl;
	SortAlgorithms *sort=new SortAlgorithms();
	sort->init();
}

#endif /* BSTREE_H_ */
