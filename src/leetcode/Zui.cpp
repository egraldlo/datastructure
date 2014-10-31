/*
 * Zui.cpp
 *
 *  Created on: 2014-10-31
 *      Author: casa
 */

#include "Zui.h"

Zui::Zui() {
	// TODO 自动生成的构造函数存根

}

Zui::~Zui() {
	// TODO 自动生成的析构函数存根
}

void Zui::longest_common_sequence(const char *str1, const char *str2){
	/* 字符串最长公共子序列， 首先子序列不是保证连续的
	 * 1，最容易想到的“简单”的方法是求出str1的所有子序列，然后再去str2中看是不是在其中
	 *   这种方法的时间复杂度是2的n次方级别的
	 * 2，动态规划的方法：
	 *   当X为x1,x2,x3,...,xm；当Y为y1,y2,y3,...,yn
	 *   dp[i][j]=0 如果i=0或j=0
	 *   dp[i][j]=dp[i-1][j-1]+1，当x[i-1]=y[j-1]
	 *   dp[i][j]=max{dp[i][j-1], dp[i-1][j]}，当x[i-1]!=y[j-1]
	 *
	 * 3，从字符串的首字符开始，然后往后，这里的dp和x,y数组不同，这里的dp是需要有为0的一行一列的
	 *   所以dp[i][j]在x和y中是i-1，j-1
	 * */
	int len1=strlen(str1);
	int len2=strlen(str2);
	cout<<"str1 length is: "<<len1<<endl;
	cout<<"str2 length is: "<<len2<<endl;

	const char *x=str1;
	const char *y=str2;

	int dp[len1+1][len2+1];
	for(int i=0;i<=len1;i++)
		for(int j=0;j<=len2;j++)
			dp[i][j]=0;

	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(x[i-1]==y[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else if(dp[i-1][j]<dp[i][j-1]) {
				dp[i][j]=dp[i][j-1];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	cout<<"the longest sequence is: "<<dp[len1][len2]<<endl;
	/* 怎样输出这写字符串呢？ */

	int len=dp[len1][len2];
	char lcs[10]={'\0'};
	int i=len1;
	int j=len2;
	while(i&&j) {
		if(x[i-1]==y[j-1]&&dp[i][j]==dp[i-1][j-1]+1){
			lcs[--len]=x[i-1];
			i--;
			j--;
		}
		else if(x[i-1]!=y[j-1]&&dp[i-1][j]>dp[i][j-1]){
			--i;
		}
		else{
			j--;
		}
	}

	cout<<"lcs: "<<lcs<<endl;
}

void Zui::longest_common_substring(const char *str1, const char *str2){
	/* 最长公共子串，找出一个字符串str1中的所有字串，然后挨个看是否全在str2中，时间复杂度是
	 * n的平方，同时还要对每个子串和str2做匹配。时间复杂度将会增大到n的4次方
	 *
	 * 当x[i-1]=y[j-1],dp[i][j]=dp[i-1][j-1]+1
	 * 当x[i-1]!=y[j-1],dp[i][j]=0，因为需要连续，如果不相等就置0
	 *  */
	int len1=strlen(str1);
	int len2=strlen(str2);
	cout<<"str1 length is: "<<len1<<endl;
	cout<<"str2 length is: "<<len2<<endl;

	const char *x=str1;
	const char *y=str2;

	int dp[len1+1][len2+1];
	for(int i=0;i<=len1;i++)
		for(int j=0;j<=len2;j++)
			dp[i][j]=0;

	int max=0;
	/* dp[i][j]可以看做是x[i]和y[j]之前最近的公共子串长度 */
	for(int i=1;i<=len1;i++) {
		for(int j=1;j<=len2;j++) {
			if(x[i-1]==y[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			if(dp[i][j]>max)
				/* 可以在这里记录下字符串的首地址. */
				max=dp[i][j];
		}
	}

	cout<<"the longest common substring: "<<max<<endl;
}

void Zui::longest_repeat_substring(const char *str1, const char *str2){

}

void Zui::longest_non_repeat_substring(const char *str1, const char *str2){

}

void Zui::longest_palindrome_substring(const char *str1, const char *str2){

}

void Zui::longest_increasing_sequence(const char *str1, const char *str2){

}

void Zui::largest_subArray_sum(const char *str1, const char *str2){

}
