/*
 * ClaimsHDFS.cpp
 *
 *  Created on: 2014-5-12
 *      Author: casa
 */

#include "ClaimsHDFS.h"

ClaimsHDFS::ClaimsHDFS() {

}

ClaimsHDFS::~ClaimsHDFS() {

}

void ClaimsHDFS::claimsRead(){
	hdfsFS fs;
	hdfsFile fd;
	string filename="/home/casa/data/kmeans_data.txt";
	fs=hdfsConnect("10.11.1.174",9000);
	fd=hdfsOpenFile(fs,filename.c_str(),O_RDONLY,0,0,0);
	if(!fd){
		cout<<"failed to open hdfs file!!!"<<endl;
	}

	char array[72];
    tSize bytes=hdfsRead(fs,fd,array,72);
	cout<<"string is: "<<array<<endl;

	hdfsCloseFile(fs,fd);
	hdfsDisconnect(fs);
}
