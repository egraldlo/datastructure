#include "tree/BStree.h"
#include "sort/SortAlgorithms.h"
#include "external/ClaimsHDFS.h"

#include <iostream>
using namespace std;

int main(){
	BStree<int> * bst=new BStree<int>();
	bst->Insert(1);
	bst->Delete(2);
	bst->Display();


	cout<<"---------------bound------------"<<endl;

	SortAlgorithms *sort=new SortAlgorithms();
	sort->init();

	ClaimsHDFS *ch=new ClaimsHDFS();
	ch->claimsRead();

	return 0;
}
