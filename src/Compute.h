/*
 * Compute.h
 *
 *  Created on: 2014-4-12
 *      Author: casa
 */

#ifndef COMPUTE_H_
#define COMPUTE_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <stdlib.h>

#define T1 4
#define T2 5
#define HASH 41
#define NODES 10
#define TEST 100

struct histogram{
	int node_id;
	int hist[HASH];
};

struct table{
   int table_id;
	vector<histogram> vh;
};

typedef int cost;

class Compute {
public:
	Compute();
	virtual ~Compute();

	void init(int tableId,unsigned partitions){
		t[tableId].table_id=tableId;
		vector<histogram> vh1;
		histogram h;
		for(unsigned i=0;i<partitions;i++){
			h.node_id=rand()%NODES;
			for(unsigned j=0;j<HASH/4;j++){
				h.hist[j]=10%TEST;
			}
			for(unsigned j=HASH/4;j<HASH;j++){
				h.hist[j]=1%TEST;
			}
//			for(unsigned j=0;j<HASH;j++){
//				h.hist[j]=5%TEST;
//			}
			t[tableId].vh.push_back(h);
		}
	}

	void print(int table){
		cout<<"table id: "<<table<<endl;
		cout<<"histogram is: "<<t[table].vh.size()<<endl;
		for(unsigned i=0;i<t[table].vh.size();i++){
			cout<<"this partition is in: "<<t[table].vh[i].node_id<<" ";
			for(unsigned j=0;j<HASH;j++){
				cout<<" "<<t[table].vh[i].hist[j];
			}
			cout<<endl<<endl;
		}
	}

	bool inNodes(int node,vector<int> nodes){
		for(unsigned i=0;i<nodes.size();i++){
			if(node==nodes[i])
				return true;
		}
		return false;
	}

	unsigned nodeTh(int node,vector<int> nodes){
		unsigned rt;
		for(unsigned i=0;i<nodes.size();i++){
			if(node==nodes[i])
				rt=i;
		}
		return rt;
	}

	//计算出每个节点集合的代价
	cost choose(vector<int> nodes){
		cost rt=0;
		int hashvalue=nodes.size();
		for(unsigned i=0;i<2;i++){
			//遍历两个表中的统计数据
			for(unsigned j=0;j<t[i].vh.size();j++){
				if(!inNodes(t[i].vh[j].node_id,nodes)){
					//如果其中一个含有数据的node没有在nodes中
					for(unsigned k=0;k<HASH;k++){
						rt+=t[i].vh[j].hist[k];
					}
				}
				else{
					//如果该节点在nodes集合中，那就看他排名多少，也就式计算出哈希值，将histogram的
					//哈希值在分配一下，在哈希值之外的相加
					unsigned th=nodeTh(t[i].vh[j].node_id,nodes);
					for(unsigned k=0;k<HASH;k++){
						if(th==k%hashvalue){
							continue;
						}
						else{
							rt+=t[i].vh[j].hist[k];
						}
					}
				}
			}
		}
		return rt;
	}

	vector<int> distinctNodes(){
		vector<int> rt;
		bool in;
		for(unsigned i=0;i<2;i++){
			for(unsigned j=0;j<t[i].vh.size();j++){
				for(unsigned k=0;k<rt.size();k++){
					if(t[i].vh[j].node_id==rt[k]){
						in=true;
						break;
					}
					else{
						in=false;
					}
				}
				if(in==false){
					rt.push_back(t[i].vh[j].node_id);
				}
				else{
					continue;
				}
			}
		}
		return rt;
	}

private:
	table t[2];
};

#endif /* COMPUTE_H_ */
