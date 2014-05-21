#include "leetcode/Lee.h"
#include "common/data_type.h"

#include <iostream>
using namespace std;

int main(){
	cout<<"LEETCODE学习！"<<endl;
	Lee *lee=new Lee();
	lee->start();

	cout<<endl<<"数据类型练习！"<<endl;
	data_type *dt=new data_type();
	dt->test();
	return 0;
}
