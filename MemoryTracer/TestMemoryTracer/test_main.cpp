#include <iostream>
#include "../MemoryTracer/Tracer.h"
#include <vector>
#include <memory>

class A
{
public:
	A()
	{
		TRACE();//�������Ҫ�ӣ����ִ���
	}
	~A()
	{
		TRACE();//�������Ҫ�ӣ����ִ���
	}
};

A* CreateA(void)
{
	return new A;
}

void f(void)
{
	auto p = new A;
	//do some thing

	//����й©��һ��
}

int main(int argc, char* argv[])
{
	auto pa = new A;//����й©1��
	new A[5];//����й©5��

	auto p2 = CreateA();
	delete p2;

	f();//����й©��1��

	auto listA = std::vector<std::shared_ptr<A>>(5, std::make_shared<A>());//����û��й¶
	for (int i = 0; i < 3; ++i)
	{
		listA.push_back(std::make_shared<A>());//����û��й©
	}
}