#ifndef _COUNTDATA_H_
#define _COUNTDATA_H_
#include <assert.h>
#include <iostream>
#include <atomic>
#include <string>

/*
author: toy_lee5566(weixin)
*/

class CountData{
public:
	CountData(const char* name)
		:m_name(name)
	{
	};
	~CountData(){ std::cout << m_name<<" leak num =" << counter_ << std::endl; };
	void inc(){
		++counter_;
	}
	void dec(){
		--counter_;
		assert(counter_ >= 0);
	}
private:
	int64_t counter_;
	std::string m_name;
};
template<typename T>
class Counter{
public:
	Counter(){ data_.inc(); }
	~Counter(){ data_.dec(); }
	Counter(const Counter&){ data_.inc(); }
private:
	static CountData data_;

};
//TIPS:ģ����ľ�̬��Ա���Զ�����ͷ�ļ��У������ӳ������⴦��
template<typename T>
CountData Counter<T>::data_ = CountData(typeid(T).name());
#endif