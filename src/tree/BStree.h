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

/*
 * 二叉树性质：
 * 1，若节点的左子树不空，左子树中所有节点值均小于根节点
 * 2，若节点的右子树不空，右子树中所有节点值均大于根节点
 * 3，左右子树都是二叉树
 * 4，没有键值相等的节点
 * */

template <class Value>
class BStree {
public:
	template <typename V>
	struct node{
		V value;
		node * left;
		node * right;
	};

public:
	//构造的时候应该是一棵空树
	BStree();
	virtual ~BStree();

private:	
	void Insert();
	void Delete();
	void Display();

private:
	node<V> * root;
};

#endif /* BSTREE_H_ */
