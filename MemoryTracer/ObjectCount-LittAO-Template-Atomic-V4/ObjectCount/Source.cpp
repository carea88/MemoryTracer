
#include "CountData.hpp"
#include <memory>
#include <vector>
#include <thread>
#include <future>

class A{
	Counter<A> count_; //����˽�г�Ա����
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
	//����й©��һ��
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
	Counter<MyClass> count_; //����˽�г�Ա����
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
	Counter<B> count_; //����˽�г�Ա����
};

B::B()
{
}

B::~B()
{
}

struct C
{
	Counter<C> count_; //����˽�г�Ա����
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