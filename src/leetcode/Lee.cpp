/*
 * Lee.cpp
 *
 *  Created on: 2014-5-20
 *      Author: casa
 */

#include "Lee.h"
#include <string.h>
#include "Tree/TraverseBinaryTree.h"
#include "/usr/include/stdio.h"

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

int Lee::fork_test() {
	//fork调用失败会返回-1，调用成功的话，在子进程中会返回0，
	//在父进程中会返回

	pid_t pid;
	int n;
	char *message;
	pid=fork();
	if(pid==0) {
		n=3;
		message="hello, I am in child!";
	}
	else if (pid>0){
		n=6;
		message="hello, I am in father!";
	}
	else{
		message="error in fork a process!";
	}

	while(n-->0)
		sleep(1);

	cout<<message<<endl;

	return 0;
}

int Lee::fork_test2() {
	int a =10;
	fork()||fork();
	sleep(1111);
	return 0;
}

int Lee::pipe_test() {
	pid_t pid;

	char *message="hello pipe!";
	char *line=new char[20];
	int files[2];
	int err=pipe(files);
	if(err<0){
		cout<<"pipe error!"<<endl;
	}
	else{
		pid=fork();
		if(pid<0)
			cout<<"fork process error!"<<endl;
		else if(pid==0){
			cout<<"in the child!"<<endl;
			close(files[0]);
			write(files[1],message,10);
		}
		else {
			cout<<"in the father!"<<endl;
			close(files[1]);
			read(files[0],line,10);
			write(1,line,10);
		}
	}
	return 0;
}

int Lee::fork_test3() {
	int i;
	for(i=0;i<2;i++){
		fork();
		printf("- %d",getpid());
	}
	return 0;
}
