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
}

ListNode* List::getRoot(){
	return head;
}

ListNode *List::sortList(ListNode *&head){
	ListNode *tmp=(ListNode *)malloc(11*sizeof(ListNode));
	sorter(head,tmp,0,10);
}

bool List::sorter(ListNode *list, ListNode *temp, int start, int end){
	if(start==end)
		return false;
	int middle=(start+end)/2;
	sorter(list,temp,start,middle);
	sorter(list,temp,middle+1,end);
	merge(list,temp,start,end,middle);
}

ListNode *List::Trans(ListNode *l, int node){
	ListNode *rt=l;
	int i=0;
	while(i<node){
		rt=rt->next;
		i++;
	}
	return rt;
}

void List::merge(ListNode *list, ListNode *temp, int start, int end, int middle){
	temp=list;
	print(list);
	int k=start;
	int i=start;
	int j=middle+1;
	while((i<=middle)&&(j<=end)){
		if(Trans(temp,i)->val<=Trans(temp,j)->val){
			cout<<Trans(temp,i)->val<<"<"<<Trans(temp,j)->val<<endl;
			cout<<"choose one: "<<Trans(temp,i)->val<<endl;
			Trans(list,k)->val=Trans(temp,i)->val;
			k++;
			i++;
		}
		else{
			cout<<Trans(temp,i)->val<<">"<<Trans(temp,j)->val<<endl;
			cout<<"choose one: "<<Trans(temp,j)->val<<endl;
			Trans(list,k)->val=Trans(temp,j)->val;
			k++;
			j++;
		}
	}
	while(i<=middle){
		Trans(list,k)->val=Trans(temp,i)->val;
		cout<<"i++choose one: "<<Trans(temp,i)->val<<endl;
		k++;
		i++;
	}
	while(j<=end){
		Trans(list,k)->val=Trans(temp,j)->val;
		cout<<"j++choose one: "<<Trans(temp,j)->val<<endl;
		k++;
		j++;
	}
	cout<<"****finish****"<<endl;
}

void List::print(ListNode *h){
	ListNode *node=h;
	while(node!=0){
		cout<<" : "<<node->val;
		node=node->next;
	}
	cout<<endl;
}
