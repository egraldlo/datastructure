/*
 * List.cpp
 *
 *  Created on: 2014-7-12
 *      Author: casa
 */

#include "List.h"

List::List() {
	// TODO Auto-generated constructor stub

}

List::~List() {
	// TODO Auto-generated destructor stub
}

void List::init(){
	/* for test, there is 11 nodes */
	head=(ListNode *)malloc(sizeof(ListNode));
	head->val=9;
	head->next=0;
	ListNode *node;
	for(int i=0;i<10;i++){
		node=(ListNode *)malloc(sizeof(ListNode));
		node->val=i;
		node->next=head->next;
		head->next=node;
	}

	l1=(ListNode *)malloc(sizeof(ListNode));
	l1->val=1;
	l1->next=0;
	for(int i=0;i<10;i++){
		node=(ListNode *)malloc(sizeof(ListNode));
		node->val=30-i*3;
		node->next=l1->next;
		l1->next=node;
	}

	l2=(ListNode *)malloc(sizeof(ListNode));
	l2->val=1;
	l2->next=0;
	for(int i=0;i<10;i++){
		node=(ListNode *)malloc(sizeof(ListNode));
		node->val=20-i*1;
		node->next=l2->next;
		l2->next=node;
	}
}

ListNode* List::getRoot(){
	return head;
}

/*
 * fast and slow pointer, it's great! divided into two parts.
 * 2*n+1:
 *   fast: n times reach 1+2*n
 *   slow: n times reach 1+n(last node in first list)
 * 2*n:
 *   fast: n-1 times reach 2*n-1
 *   slow: n-1 times reach n(last node in first list)
 * */
ListNode* List::findMiddle(ListNode *head){
	ListNode *fast=head;
	ListNode *slow=head;
	while(fast->next!=0&&fast->next->next!=0){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

ListNode *List::mergeTwoList(ListNode *left, ListNode *right){
	ListNode *ret=(ListNode *)malloc(sizeof(ListNode));
	ret->val=-1;ret->next=0;
	ListNode *r=ret;
	while(left!=0&&right!=0){
		if(left->val<right->val){
			ret->next=left;
			ret=left;
			left=left->next;
		}
		else{
			ret->next=right;
			ret=right;
			right=right->next;
		}
	}
	while(left!=0){
		ret->next=left;
		ret=left;
		left=left->next;
	}
	while(right!=0){
		ret->next=right;
		ret=right;
		right=right->next;
	}
	return r->next;
}

ListNode *List::sortList(ListNode *head){
	if(head==0||head->next==0)
		return head;
	ListNode *first=head;
	ListNode *middle=findMiddle(head);
	ListNode *second=middle->next;
	middle->next=0;
	ListNode *li1=sortList(first);
	ListNode *li2=sortList(second);
	return mergeTwoList(li1,li2);
}

ListNode *List::reverseBetween(ListNode *head, int m, int n){
	ListNode *rt=(ListNode *)malloc(sizeof(ListNode));
	rt->val=-1;rt->next=0;
	int i=1;
	ListNode *p=head;
	while(i<m){
		p=p->next;
		i++;
	}


	rt->next=p;
	p->next=0;
	while()


	return rt->next;
}

void List::print(ListNode *h){
	ListNode *node=h;
	while(node!=0){
		cout<<" : "<<node->val;
		node=node->next;
	}
	cout<<endl;
}
