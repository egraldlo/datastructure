/*
 * List.h
 *
 *  Created on: 2014-7-12
 *      Author: casa
 */

#ifndef LIST_H_
#define LIST_H_

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

	void init();
	ListNode *getRoot();
	void print(ListNode *);

	ListNode *reverseBetween(ListNode *head, int m, int n);

public:
	ListNode *l1;
	ListNode *l2;

private:
	ListNode *head;
};

#endif /* LIST_H_ */
