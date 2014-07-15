#include "tree/BStree.h"
#include "sort/SortAlgorithms.h"
//#include "external/ClaimsHDFS.h"
#include "a/A1.h"
#include "b/B.h"

#include <string.h>

#include <string>

#include <iostream>
using namespace std;

int main(){
//	BStree<int> * bst=new BStree<int>();
//	bst->Insert(1);
//	bst->Delete(2);


	cout<<"---------------bound------------"<<endl;

	SortAlgorithms *sort=new SortAlgorithms();
//	sort->init();

//	ClaimsHDFS *ch=new ClaimsHDFS();
//	ch->claimsRead();

	A1 *a1=new A1();
	a1->test();

	const char *s="cddc";
	char d[5];
	strcpy(d,s);
	cout<<"d: "<<d<<endl;
	string s1=s;
	cout<<"s1: "<<s1.c_str()<<endl;

	B *bb=new B();
	bb->tes();
	bb->tes1();

	return 0;
}
