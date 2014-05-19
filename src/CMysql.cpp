#include <iostream>
using namespace std;

#include "cmysql/CMysqlServer.h"

int main(){
	cout<<"claims mysql module!"<<endl;
	CMysqlServer *cmysqlserver=new CMysqlServer();
	cmysqlserver->start();
	return 0;
}
