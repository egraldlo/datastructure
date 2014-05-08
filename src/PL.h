/*
 * PL.h
 *
 *  Created on: 2014-4-12
 *      Author: casa
 */

#ifndef PL_H_
#define PL_H_

#include <vector>
using namespace std;

#include <stdio.h>

#define MAXN 100

//
//vector<int> comb(int m,int k)
//{
//	vector<int > v;
//	int i,j;
//	for (i=m;i>=k;i--)
//	{
//		a[k]=i;
//		if(k>1)
//			comb(i-1,k-1);
//		else
//		{
//			counts++;
//			for(j=a[0];j>0;j--){
//				printf("%d ",a[j]);
//				v.push_back(a[j]);
//			}
//         printf("\n");
//		}
//	}
//	return v;
//}
//
//int main()
//{
//      int m,r;
//      printf("Please input m:");
//      scanf("%d",&m);
//      printf("Please input n:");
//      scanf("%d",&r);
//      counts=0;
//      a[0]=r;
//      comb(m,r);
//      printf("All kinds is:%d\n",counts);
//      return 0;
//}

class PL {
public:
	PL(int nodes);
	virtual ~PL();

	void prelode(int node){
		a[MAXN]={0};
		counts=0;
		a[0]=node;
	}

	void comb(int m,int k)
	{
		int i,j;
		for (i=m;i>=k;i--)
		{
			a[k]=i;
			if(k>1)
				comb(i-1,k-1);
			else
			{
				counts++;
				vector<int> v;
				for(j=a[0];j>0;j--){
//					printf("%d ",a[j]);
					v.push_back(a[j]);
				}
				vv.push_back(v);
//	         printf("\n");
			}
		}
	}

	vector<vector<int> > computes(){
		for(unsigned i=1;i<=nodes;i++){
			prelode(i);
			comb(nodes,i);
		}
		return vv;
	}

private:
	vector<vector<int> > vv;
	int nodes;
	int a[MAXN];
	int counts;
};

#endif /* PL_H_ */
