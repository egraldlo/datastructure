/*
 * CMysqlUtil.h
 *
 *  Created on: 2014-5-27
 *      Author: casa
 */

#ifndef C_MYSQL_UTIL_H_
#define C_MYSQL_UTIL_H_

#include <stdint.h>

class CMysqlUtil {
public:
	CMysqlUtil();
	virtual ~CMysqlUtil();

public:
	int store_int1(char *buf,int64_t len,int8_t v,int64_t &pos);
	int store_int2(char *buf,int64_t len,int16_t v,int64_t &pos);
	int store_int3(char *buf,int64_t len,int32_t v,int64_t &pos);
	int store_int4(char *buf,int64_t len,int32_t v,int64_t &pos);

};

#endif /* CMYSQLUTIL_H_ */
