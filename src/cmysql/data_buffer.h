/*
 * DataBuffer.h
 *
 *  Created on: 2014-5-23
 *      Author: casa
 */

#ifndef DATA_BUFFER_H_
#define DATA_BUFFER_H_

//两个类从OB中来

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

class ObDataBuffer{
public:
	ObDataBuffer():data_(NULL),capacity_(0),position_(0){}
	ObDataBuffer(char* data,const int64_t capacity):data_(data),capacity_(capacity),position_(0){}
	~ObDataBuffer(){}

	inline bool set_data(char* data, const int64_t capacity){
		bool ret = false;
		if(data!=NULL&&capacity>0){
			data_ = data;
			capacity_ = capacity;
			position_ = 0;
			limit_ = 0;
			ret = true;
		}
		return ret;
	}

	/** WARNING: make sure the memory if freed before call this method */
	inline void reset(){
		data_ = NULL;
		capacity_ = 0;
		position_ = 0;
		limit_ = 0;
	}

	inline const char* get_data() const { return data_; }
	inline char* get_data() { return data_; }

	inline int64_t get_capacity() const { return capacity_; }
	inline int64_t get_remain() const { return capacity_ - position_; }
	inline int64_t get_remain_data_len() const {return limit_ - position_; }
	inline int64_t get_position() const { return position_; }
	inline int64_t& get_position() { return position_; }

	inline int64_t get_limit() const { return limit_; }
	inline int64_t& get_limit() { return limit_; }

  private:
	char* data_;
	int64_t capacity_;
	int64_t position_;
	int64_t limit_;
};

class ThreadSpecificBuffer
{
  public:
	static const int32_t MAX_THREAD_BUFFER_SIZE = 2*1024*1024L;
  public:
	class Buffer
	{
	  public:
		Buffer(char* start, const int32_t size)
		  : end_of_storage_(start + size), end_(start)
		{
		}

	  public:
		int write(const char* bytes, const int32_t size);
		int advance(const int32_t size);
		void reset() ;

		inline int32_t used() const { return static_cast<int32_t>(end_ - start_); }
		inline int32_t remain() const { return static_cast<int32_t>(end_of_storage_ - end_); }
		inline int32_t capacity() const { return static_cast<int32_t>(end_of_storage_ - start_); }
		inline char* current() const { return end_; }

	  private:
		char* end_of_storage_;
		char* end_;
		char start_[0];
	};
  public:
	explicit ThreadSpecificBuffer(const int32_t size = MAX_THREAD_BUFFER_SIZE);
	~ThreadSpecificBuffer();

	Buffer* get_buffer() const;
  private:
	int create_thread_key();
	int delete_thread_key();
	static void destroy_thread_key(void* ptr);

	pthread_key_t key_;
	int32_t size_;
};

ThreadSpecificBuffer::ThreadSpecificBuffer(const int32_t size)
  : key_(4294967295U), size_(size){
  create_thread_key();
}

ThreadSpecificBuffer::~ThreadSpecificBuffer(){
  delete_thread_key();
}

int ThreadSpecificBuffer::create_thread_key(){
  int ret = pthread_key_create(&key_, destroy_thread_key);
  if (0!=ret){
	  cout<<"create_thread_key"<<endl;
  }
  return (0 == ret) ? 0 : 1;
}

int ThreadSpecificBuffer::delete_thread_key(){
  int ret = -1;
  if (4294967295U != key_)
  {
    ret = pthread_key_delete(key_);
  }
  if (0 != ret)
  {
    cout<<"delete thread key key_ failed."<<endl;
  }
  return (0 == ret) ? 0 : 1;
}

void ThreadSpecificBuffer::destroy_thread_key(void* ptr){
  if (NULL != ptr) ob_free(ptr);
}

ThreadSpecificBuffer::Buffer* ThreadSpecificBuffer::get_buffer() const
{
  Buffer * buffer = NULL;
  if (4294967295U != key_ && size_ > 0)
  {
    void* ptr = pthread_getspecific(key_);
    if (NULL == ptr)
    {
      ptr = ob_malloc(size_ + sizeof(Buffer), ObModIds::OB_THREAD_BUFFER);
      if (NULL != ptr)
      {
        int ret = pthread_setspecific(key_, ptr);
        if (0 != ret)
        {
          TBSYS_LOG(ERROR, "pthread_setspecific failed:%d", ret);
          ob_free(ptr);
          ptr = NULL;
        }
        else
        {
          TBSYS_LOG(DEBUG, "new thread specific buffer, addr=%p size=%d this=%p", ptr, size_, this);
          buffer = new (ptr) Buffer(static_cast<char*>(ptr) + sizeof(Buffer), size_);
        }
      }
      else
      {
        // malloc failed;
        cout<<"malloc thread specific memeory failed."<<endl;
      }
    }
    else
    {
      // got exist ptr;
      buffer = reinterpret_cast<Buffer*>(ptr);
    }
  }
  else
  {
    TBSYS_LOG(ERROR, "thread key must be initialized "
        "and size must great than zero, key:%u,size:%d", key_, size_);
  }
  return buffer;
}

int ThreadSpecificBuffer::Buffer::advance(const int32_t size)
{
  int ret = 0;
  if (size < 0)
  {
    if (end_ + size < start_)
    {
      ret = 1;
    }
  }
  else
  {
    if (end_ + size > end_of_storage_)
    {
      ret = 1;
    }
  }

  if (0 == ret) end_ += size;

  assert(end_ >= start_ && end_ <= end_of_storage_);
  return ret;
}

void ThreadSpecificBuffer::Buffer::reset()
{
  end_ = start_;
}

int ThreadSpecificBuffer::Buffer::write(const char* bytes, const int32_t size)
{
  int ret = 0;
  if (NULL == bytes || size < 0)
  {
    ret = 1;
  }
  else
  {
    if (size > remain()) ret = 1;
    else
    {
      ::memcpy(end_, bytes, size);
      advance(size);
    }
  }
  return ret;
}

#endif /* DATABUFFER_H_ */
