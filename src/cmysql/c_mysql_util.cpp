/*
 * CMysqlUtil.cpp
 *
 *  Created on: 2014-5-27
 *      Author: casa
 */

#include "c_mysql_util.h"

CMysqlUtil::CMysqlUtil() {

}

CMysqlUtil::~CMysqlUtil() {

}

int CMysqlUtil::store_int1(char *buf,int64_t len,int8_t v,int64_t &pos){
	int ret=C_SUCCESS;
	if(len>=pos+1){
		int1store(buf+pos,v);
        pos+=1;
	}
    else{
        ret=C_SIZE_OVERFLOW;
    }
    return ret;
}

int CMysqlUtil::store_int2(char *buf, int64_t len, int16_t v, int64_t &pos){
  int ret = C_SUCCESS;

  if (len >= pos + 2)
  {
    int2store(buf + pos, v);
    pos += 2;
  }
  else
  {
    ret = C_SIZE_OVERFLOW;
  }

  return ret;
}

int CMysqlUtil::store_int3(char *buf,int64_t len,int32_t v,int64_t &pos){
	int ret = C_SUCCESS;

	if (len >= pos + 3){
		int3store(buf + pos, v);
		pos += 3;
	}

	else{
		ret = C_SIZE_OVERFLOW;
	}

	return ret;
}

int CMysqlUtil::store_int4(char *buf, int64_t len, int32_t v, int64_t &pos){
  int ret = C_SUCCESS;

  if (len >= pos + 4)
  {
    int4store(buf + pos, v);
    pos += 4;
  }
  else
  {
    ret = C_SIZE_OVERFLOW;
  }

  return ret;
}
