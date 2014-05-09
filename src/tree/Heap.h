/*
 * Heap.h
 *
 *      Author: casa
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <malloc.h>

/*
 * 其实heap就是一种有序队列，普通的队列是先入先出，二叉堆是最小先出
 * 特点：父节点的值大于（小于）两个子节点的值
 * 用途：堆排序和优先队列
 * */
template <typename TV>
class Heap{
public:
	/*
	 * 二顶堆
	 * */
	template <typename T>
	struct Tnode{
		T value;
		struct Tnode *left;
		struct Tnode *right;
	};

	Heap(){};
	virtual ~Heap(){};
private:
	bool Build(TV &value){
		root=(Tnode<TV> *)malloc(sizeof(Tnode<TV>));
		root->value=value;
		root->left=0;
		root->right=0;
		return true;
	}

	/*
	 * 插入之后要堆化*/
	bool Insert(Tnode<TV> &node){

		return true;
	}

	/*
	 * 更新之后要堆化*/
	bool Update(){return true;}

	/*
	 * 获得堆的最大值或者最小值*/
	Tnode<TV> Get(){}

	/*
	 * 删除堆之后要堆化*/
	bool Delete(){return true;}

	/*
	 * 堆化*/
	bool Heapify(){return true;}

	/*
	 * 将堆输出*/
	void Print(){}

private:
	Tnode<TV> *root;
};

#endif /* HEAP_H_ */
