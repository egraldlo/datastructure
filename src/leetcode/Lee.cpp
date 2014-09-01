/*
 * Lee.cpp
 *
 *  Created on: 2014-5-20
 *      Author: casa
 */

#include "Lee.h"
#include <string.h>
#include "Tree/TraverseBinaryTree.h"

Lee::Lee() {

}

Lee::~Lee() {

}

void Lee::start(){
	cout<<"树测试："<<endl;

	TraverseBinaryTree *tbt=new TraverseBinaryTree();
	tbt->init();


}

bool isMatch(char *s1, char *s2) {
	while(*s2!='\0'){
		if(*s1++==*s2++)
			continue;
		else
			return false;
	}
	return true;
}

bool Lee::stringMatch(char *str1, char *str2) {
	int str2_len=strlen(str2);
	int str1_len=strlen(str1);

	char *t=str1;
	while(*t!='\0') {
		if(isMatch(t,str2))
			return true;
		else
			t++;
	}
	return false;
}
