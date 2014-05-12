/*
 * ClaimsHDFS.h
 *
 *  Created on: 2014-5-12
 *      Author: casa
 */

#ifndef CLAIMSHDFS_H_
#define CLAIMSHDFS_H_

#include <hdfs.h>
#include <string>
#include <iostream>
using namespace std;

class ClaimsHDFS {
public:
	ClaimsHDFS();
	virtual ~ClaimsHDFS();

public:
	void claimsRead();
};

#endif /* CLAIMSHDFS_H_ */
