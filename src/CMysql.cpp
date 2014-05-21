#include <iostream>
using namespace std;

#include "cmysql/c_mysql_server.h"

int main(){
	cout<<"claims mysql module!"<<endl;
	CMysqlServer *cmysqlserver=new CMysqlServer();
	cmysqlserver->start();
	return 0;
}
