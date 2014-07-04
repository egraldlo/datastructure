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

#include <malloc.h>

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
	node<Value> *getRoot(){
		return root;
	};

	bool Insert(Value value);
	bool Delete(Value value);
	bool Search(node<Value> *treenode,Value value);

	int Display(node<Value> *root);

	void Recurse_PreorderTraverse(node<Value> *root);
	void Recurse_PostorderTraverse(node<Value> *root);
	void Recurse_InorderTraverse(node<Value> *root);

	void Iterate_PreorderTraverse(node<Value> *root);
	void Iterate_PostorderTraverse(node<Value> *root);
	void Iterate_InorderTraverse(node<Value> *root);

private:
	node<Value> * root;
};

//template <typename Value>
//BStree::node<Value> * BStree<Value>::
//getRoot(){
//	return root;
//}

//C++编译器不支持对模板的分离式编译，将成员函数的实现放在.h文件中
template <typename Value>
bool BStree<Value>::
Insert(Value value){
//	Insert(node<Value> *treenode, Value value){
//	if(!Search(treenode,value)){
//
//	}
//	else{
//		return false;
//	}
	cout<<"待完善的接口！"<<endl;
	return true;
}

template <typename Value>
bool BStree<Value>::
Delete(Value value){
	return true;
}

template <typename Value>
bool BStree<Value>::
Search(node<Value> *treenode,Value value){
	cout<<"search the tree!"<<endl;
	if(treenode->left==0&&treenode->right==0){
		return false;
	}else{
		if(treenode->value==value)
			return true;
		else{
			if(treenode->value<value)
				Search(treenode->right,value);
			else
				Search(treenode->left,value);
		}
	}
}

template <typename Value>
int BStree<Value>::
Display(node<Value> *root){
	if(root==0){
		return 0;
	}
	else{
		cout<<"=========== tree node value is: "<<root->value<<endl;
		if(root->left!=0){
			Display(root->left);
		}
		if(root->right!=0){
			Display(root->right);
		}
	}
}

/* 二叉搜索树的遍历一般分为迭代方式和递归方式两种
 * 在迭代方式中，需要用栈模拟出递归的效果，其中前序和中序相似，但是后序有点不同
 *  */
template <typename Value>
void BStree<Value>::
Recurse_PreorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Recurse_InorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Recurse_PostorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Iterate_PreorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Iterate_InorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Iterate_PostorderTraverse(node<Value> *root){

}

#endif /* BSTREE_H_ */
