
#include "CountData.hpp"
#include <memory>
#include <vector>
#include <thread>
#include <future>

class A{
	Counter<A> count_; //引入私有成员变量
};
A* CreateA(void)
{
	return new A;
}

void f(void)
{
	auto p = new A;
	//do some thing
	delete p;
	//这里泄漏了一次
}
void f10000(void)
{
	for (int i = 0; i < 10000; ++i)
	{
		f();
	}
}
class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	Counter<MyClass> count_; //引入私有成员变量
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

class B
{
public:
	B();
	~B();

private:
	Counter<B> count_; //引入私有成员变量
};

B::B()
{
}

B::~B()
{
}

struct C
{
	Counter<C> count_; //引入私有成员变量
};
int main(){

	std::future<void> futureResult1 = std::async(std::launch::async, f10000);
	std::future<void> futureResult2 = std::async(std::launch::async, f10000);
	std::future<void> futureResult3 = std::async(std::launch::async, f10000);
	std::future<void> futureResult4 = std::async(std::launch::async, f10000);

	futureResult1.get();
	futureResult2.get();
	futureResult3.get();
	futureResult4.get();

	return 0;
}