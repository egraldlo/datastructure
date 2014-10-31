/*
 * Zui.h
 *
 *  Created on: 2014-10-31
 *      Author: casa
 */

#ifndef ZUI_H_
#define ZUI_H_

#include <iostream>
using namespace std;

#include <string.h>

class Zui {
public:
	Zui();
	virtual ~Zui();

public:
	/* 子序列是不必要求连续的 */
	/* 字串是要求连续的 */
	void longest_common_sequence(const char *str1, const char *str2);
	void longest_common_substring(const char *str1, const char *str2);
	void longest_repeat_substring(const char *str1, const char *str2);
	void longest_non_repeat_substring(const char *str1, const char *str2);
	void longest_palindrome_substring(const char *str1, const char *str2);
	void longest_increasing_sequence(const char *str1, const char *str2);
	/* 连续子数组最大和 */
	void largest_subArray_sum(const char *str1, const char *str2);

	void test() {
		cout<<"please choose the certain algorithm!"<<endl;
		cout<<"1，最长公共子序列"<<endl;
		cout<<"2，最长公共子串"<<endl;
		cout<<"3，最长重复子串"<<endl;
		cout<<"4，最长不重复子串"<<endl;
		cout<<"5，最长回文子串"<<endl;
		cout<<"6，最长递增子序列"<<endl;
		cout<<"7，最长子数组之和"<<endl;
		const char *p="abcbdab";//"hellohello";
		const char *q="bdcaba";//"llehellollo";
		int choose;
		cin>>choose;
		switch(choose) {
		case 1:
			longest_common_sequence(p,q);
			break;

		case 2:
			longest_common_substring(p,q);
			break;

		case 3:
			longest_repeat_substring(p,q);
			break;

		case 4:
			longest_non_repeat_substring(p,q);
			break;

		case 5:
			longest_palindrome_substring(p,q);
			break;

		case 6:

		}
	}
private:

};

#endif /* ZUI_H_ */
