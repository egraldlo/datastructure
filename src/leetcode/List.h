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

	ListNode *sortList(ListNode *&head);
	ListNode *Trans(ListNode *l, int node);
	bool sorter(ListNode *list, ListNode *temp, int start, int end);
	void merge(ListNode *list, ListNode *temp, int start, int end, int middle);


	void init();
	ListNode *getRoot();
	void print(ListNode *);
private:
	ListNode *head;
};

#endif /* LIST_H_ */
