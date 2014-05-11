#include "tree/BStree.h"

#include <iostream>
using namespace std;

int main(){
	BStree<int> * bst=new BStree<int>();
	bst->Insert(1);
	bst->Delete(2);
	bst->Display();
	return 0;
}
