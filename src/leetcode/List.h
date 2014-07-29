/*
 * List.h
 *
 *  Created on: 2014-7-12
 *      Author: casa
 */

#ifndef LIST_H_
#define LIST_H_

#include <vector>
#include <iostream>
using namespace std;

#include <malloc.h>

struct ListNode{
	int val;
	ListNode *next;
};

class List {
public:
	List();
	virtual ~List();

	ListNode *sortList(ListNode *head);
	ListNode *findMiddle(ListNode *head);
	ListNode *mergeTwoList(ListNode *left, ListNode *right);
	ListNode *mergeLists(vector<ListNode *>);

	void init();
	void reset();
	ListNode *getRoot();
	void print(ListNode *);

	ListNode *reverseBetween(ListNode *head, int m, int n);

public:
	ListNode *l1;
	ListNode *l2;
	ListNode *l3;

private:
	ListNode *head;
};

struct DListNode{
	int val;
	DListNode *pre,*next;
};

class DList{
public:
	DList(){};
	~DList(){};

private:
	DListNode *root;
};

#endif /* LIST_H_ */
