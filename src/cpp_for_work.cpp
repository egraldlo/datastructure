//============================================================================
// Name        : cpp_for_work.cpp
// Author      : casa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "tree/Btree.h"
#include "tree/AVLtree.h"

#include "sec/Try.h"

#include "sync/pro_cus.h"
#include "sync/BarrierTest.h"

#include "exception.h"
#include "daemon.h"
#include "fork.h"
#include "SParent.h"
#include "SChild1.h"
#include "affinity.h"
#include "processor.h"
#include "HashTable.h"
#include "BitMap.h"
#include "RegisterChild.h"

#include "choose.cpp"

#include <iostream>
#include <sstream>
using namespace std;

#include <string>


void test_avltree(){
	AVLtree<int> *avl=new AVLtree<int>();
	int i1=10;
	int i2=19;
	int i3=24;
	int i4=4;
	int i5=6;
	avl->Build(i1);
	avl->Insert(i2,avl->root);
	avl->Insert(i3,avl->root);
	avl->Insert(i4,avl->root);
	avl->Insert(i5,avl->root);
	avl->Print(avl->root);
}

void test_pc(){
	producer_consumer();
}

int test_daemon(){
	cdaemon(0,0);
	sleep(1000);
	return 0;
}

int test_fork(){
	cfork();
	return 0;
}

int test_exception(){
	cexception();
	return 0;
}

int test_serObject(){
	SParent *sc=new SChild(1234567);
	SParent *c1_1=new SChild1(1234321,sc);

	std::ostringstream os;
	std::cout<<"----------"<<endl;
	boost::archive::text_oarchive oa(os);
	std::cout<<"----------"<<endl;
	Register_children(oa);
	oa<<c1_1;
	std::cout<<"----------"<<endl;

	std::cout<<"after serial the os is: "<<os.str().c_str()<<std::endl;

	std::istringstream is(os.str());
	boost::archive::text_iarchive ia(is);
	Register_children(ia);
	SParent *cs;

	ia>>cs;
	cs->f1();

	SChild1 *sc1=reinterpret_cast<SChild1*>(cs);
	SChild *sc_=reinterpret_cast<SChild*>(sc1->child);
	sc_->f1();
	return 0;
}

int test_barrier(){
	BarrierTest *bt=new BarrierTest(3);
	bt->init();
	bt->funcAdd();
	bt->funcAdd();
	bt->funcAdd();
	for(unsigned i=0;i<(bt->ps).size();i++){
		pthread_join((bt->ps)[i],NULL);
	}
	return 0;
}

int test_btree(){
	TreeNode *tn=new TreeNode();
	Btree *t=new Btree(tn);
	t->insert(3);
	t->insert(2);
	t->insert(4);
	t->display();
	return 0;
}

int test_processor(){
	processor();
	return 0;
}

int test_affinity(){
	affinity();
	return 0;
}

int test_hashtable(){
	HashTable *ht=new HashTable(4,4096,4);
	void *p=ht->allocate(1);
	*(int *)(p)=4;
	HashTable::HashTableIterator it=ht->createIterator();
	ht->placeIterator(it,1);
	cout<<"input: "<<*reinterpret_cast<int *>(it.readnext());
	return 0;
}

int test_bitmap(){
	BitMap *bm_1=new BitMap();
	bm_1->BitMap_init(15);
	bm_1->BitMap_set(1);
	bm_1->BitMap_set(3);
	bm_1->BitMap_set(5);
	for(int i=0;i<24;i++){
		std::cout<<"the bit is:"<<	bm_1->BitMap_get(i)<<std::endl;
	}

	BitMap *bm_2=new BitMap();
	bm_2->BitMap_init(15);
	bm_2->BitMap_set(3);
	bm_2->BitMap_set(5);
	for(int i=0;i<24;i++){
		std::cout<<"the bit is:"<<	bm_2->BitMap_get(i)<<std::endl;
	}

	BitMap *bm=bm_1->BitMap_merge(bm_2);
	for(int i=0;i<24;i++){
		std::cout<<"the bit is:"<<bm->BitMap_get(i)<<std::endl;
	}

	std::cout<<"copy constructor func"<<std::endl;
	BitMap *_bm=new BitMap((*bm));
	for(int i=0;i<24;i++){
			std::cout<<"the bit is:"<<_bm->BitMap_get(i)<<std::endl;
		}
	return 0;
}

int main(){
	cout<<"hello?"<<endl;
	Try * t=new Try();
	t->print();
	test_barrier();
//	test_avltree();
	test_pc();
//	test_daemon();
//	test_fork();
//	test_exception();
//	test_serObject();
//	test_barrier();
//	test_btree();
//	test_affinity();
//	test_processor();
//	test_hashtable();
//	test_bitmap();
	return 0;
}

