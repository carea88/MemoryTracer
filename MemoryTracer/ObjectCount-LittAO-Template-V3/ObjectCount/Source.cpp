
#include "CountData.hpp"
#include <memory>
#include <vector>
#include "Tracer2.h"

class A
{
public:
	//Counter<A> count_; //����˽�г�Ա����
	A()
	{

	}
	~A()
	{

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

class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	//Counter<MyClass> count_; //����˽�г�Ա����
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
	//Counter<B> count_; //����˽�г�Ա����
};

B::B()
{
}

B::~B()
{
}

struct C
{
	//Counter<C> count_; //����˽�г�Ա����
};
int main(){
	auto pa = new A;//����й©1��

	auto aa = new A[5];//����й©5��

	auto p2 = CreateA();
	delete p2;

	f();//����й©��1��
	new MyClass;//����й©��һ��
	new B;//����й©��һ��
	auto listA = std::vector<std::shared_ptr<A>>(5, std::make_shared<A>());//����û��й¶
	for (int i = 0; i < 3; ++i)
	{
	listA.push_back(std::make_shared<A>());//����û��й©
	}
	auto pc = new C;
	delete pc;

	return 0;
}