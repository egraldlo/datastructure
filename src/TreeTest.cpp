#include "tree/BStree.h"
#include "sort/SortAlgorithms.h"

#include <iostream>
using namespace std;

int main(){
	BStree<int> * bst=new BStree<int>();
	bst->Insert(1);
	bst->Delete(2);
	bst->Display();

	SortAlgorithms *sort=new SortAlgorithms();
	sort->test();
	return 0;
}
