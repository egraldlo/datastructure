//============================================================================

// Name        : choose.cpp
// Author      : casa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include "Compute.h"
#include "PL.h"

//void pl(int num){
//	vector<vector<int> > rt;
//	int total=1;
//	for(int i=1;i<=num;i++){
//		total*=i;
//	}
//	cout<<"total is: "<<total<<endl;
//}

static int choose(){
	Compute *c=new Compute();
	c->init(0,T2);
	c->print(0);

	c->init(1,T1);
	c->print(1);

	vector<int> cc=c->distinctNodes();
	for(unsigned k=0;k<cc.size();k++){
		cout<<" "<<cc[k];
	}
	cout<<"happy: "<<cc.size()<<endl;

	///////////////////10 nodes
	PL *pl=new PL(NODES);
	cc.clear();
	for(unsigned i=0;i<NODES;i++){
		cc.push_back(i+1);
	}
	///////////////////10 nodes
//	PL *pl=new PL(cc.size());
	vector<vector<int> > vvi=pl->computes();
	for(unsigned o=0;o<vvi.size();o++){
		cout<<"oooo: ";
		for(unsigned h=0;h<vvi[o].size();h++){
			cout<<" "<<vvi[o][h];
		}
		cout<<endl;
	}

	vector<vector<int> > new_vvi;
	int b[NODES]={0};
	for(unsigned k=0;k<vvi.size();k++){
		for(unsigned l=0;l<vvi[k].size();l++){
			b[l]=vvi[k][l];
		}
		do{
			vector<int> new_vi;
			for(unsigned m=0;m<vvi[k].size();m++){
				new_vi.push_back(b[m]);
			}
			if(new_vi.size()!=0){
				new_vvi.push_back(new_vi);
			}
		}while(prev_permutation(b,b+vvi[k].size()));
	}

//	for(unsigned x=0;x<new_vvi.size();x++){
//		cout<<"new_vvi: ";
//		for(unsigned y=0;y<new_vvi[x].size();y++){
//			cout<<" "<<new_vvi[x][y];
//		}
//		cout<<endl;
//	}

//	sleep(11111111);
//	Compute *c=new Compute();
//	c->init(0,T2);
//	c->print(0);
//
//	c->init(1,T1);
//	c->print(1);


//	for(unsigned l=0;l<new_vvi.size();l++){
//		cout<<"begin: ";
//		for(unsigned ll=0;ll<new_vvi[l].size();ll++){
//			cout<<" "<<new_vvi[l][ll];
//		}
//		cout<<endl;
//	}


	int min=0,max=0;
	int maxv=0,minv=0;
	max=c->choose(new_vvi[0])/(new_vvi[0].size());
	min=c->choose(new_vvi[0])/(new_vvi[0].size());


//	for(unsigned o=0;o<new_vvi.size();o++){
//		cout<<"oooo: ";
//		for(unsigned h=0;h<new_vvi[o].size();h++){
//			cout<<" "<<new_vvi[o][h];
//		}
//		cout<<endl;
//	}


	vector<vector<int> >  new_vvi_i;
	for(unsigned m=0;m<new_vvi.size();m++){
		vector<int> vvv;
		for(unsigned n=0;n<new_vvi[m].size();n++){
			vvv.push_back(cc[new_vvi[m][n]-1]);
		}
		new_vvi_i.push_back(vvv);
	}

//	for(unsigned o=0;o<new_vvi_i.size();o++){
//		cout<<"oooo: ";
//		for(unsigned h=0;h<new_vvi_i[o].size();h++){
//			cout<<" "<<new_vvi_i[o][h];
//		}
//		cout<<endl;
////		usleep(5000);
//	}

	cout<<"max: "<<max<<endl;
	cout<<"min: "<<min<<endl;
	for(unsigned t=0;t<new_vvi_i.size();t++){
//		cout<<"is: "<<c->choose(new_vvi_i[t])<<endl;
		if(c->choose(new_vvi_i[t])/(new_vvi_i[t].size())<min){
//			minv.clear();
			min=c->choose(new_vvi_i[t])/(new_vvi_i[t].size());
			minv=new_vvi_i[t].size();
//			for(unsigned i=0;i<new_vvi[t].size();i++){
//				minv.push_back(new_vvi[t][i]);
//			}
		}
		if(c->choose(new_vvi_i[t])>max){
//			maxv.clear();
			max=c->choose(new_vvi_i[t])/(new_vvi_i[t].size());
			maxv=new_vvi_i[t].size();
			cout<<"caonima"<<endl;
			getchar();
//			for(unsigned i=0;i<new_vvi[t].size();i++){
//				maxv.push_back(new_vvi[t][i]);
//			}
		}
//		cout<<c->choose(new_vvi[t])<<"is the cost of: ";
//		for(unsigned r=0;r<new_vvi[t].size();r++){
//			cout<<" "<<new_vvi[t][r];
//		}
//		cout<<endl;
	}
	cout<<"max: "<<max<<"min: "<<min<<endl;
	cout<<"maxv: "<<maxv<<endl;
//	for(unsigned i=0;i<maxv.size();i++)
//		cout<<" "<<maxv[i];
//	cout<<endl;

	cout<<"minv: "<<minv<<endl;
//	for(unsigned i=0;i<minv.size();i++)
//		cout<<" "<<minv[i];
//	cout<<endl;

	//	//for test
//	vector<int> v1;
//	v1.push_back(0);
//	v1.push_back(1);
//
//	vector<int> v2;
//	v2.push_back(2);
//	v2.push_back(1);
//
//	vector<int> v3;
//	v3.push_back(1);
//
//	cout<<"v1 cost is 0 1:"<<c->choose(v1)<<endl;
//	cout<<"v2 cost is 2 1:"<<c->choose(v2)<<endl;
//	cout<<"v3 cost is 1:"<<c->choose(v3)<<endl;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

//int main1(){
//	int a[]={3,1,2};
//	do{
//		cout << a[0] << " " << a[1] << " " << a[2] << endl;
//	}while (prev_permutation(a,a+2));
//	return 0;
//}
