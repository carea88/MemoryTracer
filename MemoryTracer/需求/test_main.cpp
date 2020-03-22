#include <iostream>
#include "../MemoryTracer/Tracer.h"
#include <vector>
#include <memory>

class A
{
public:
	A()
	{
		TRACE();//这里必须要加，入侵代码
	}
	~A()
	{
		TRACE();//这里必须要加，入侵代码
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

	//这里泄漏了一次
}

int main(int argc, char* argv[])
{
	auto pa = new A;//这里泄漏1次
	new A[5];//这里泄漏5个

	auto p2 = CreateA();
	delete p2;

	f();//这里泄漏了1次

	auto listA = std::vector<std::shared_ptr<A>>(5, std::make_shared<A>());//这里没有泄露
	for (int i = 0; i < 3; ++i)
	{
		listA.push_back(std::make_shared<A>());//这里没有泄漏
	}
}