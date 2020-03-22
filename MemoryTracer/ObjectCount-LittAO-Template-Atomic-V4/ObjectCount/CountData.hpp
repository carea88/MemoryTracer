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
		:m_name(name),counter_(0)
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
	std::atomic<long long> counter_;
	std::string m_name;
};
template<typename T>
class Counter{
public:
	Counter(){ m_data.inc(); }
	~Counter(){ m_data.dec(); }
	Counter(const Counter&){ m_data.inc(); }
private:
	static CountData m_data;

};
//TIPS:ģ����ľ�̬��Ա���Զ�����ͷ�ļ��У������ӳ������⴦��
template<typename T>
CountData Counter<T>::m_data(typeid(T).name());
#endif