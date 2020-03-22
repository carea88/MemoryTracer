#pragma once
//class Tracer
//{
//public:
//	Tracer();
//	~Tracer();
//};
#include <cstdlib>
#include <exception>
//#include <string>
//#include <iostream>

void * operator new(size_t size);

void operator delete(void* mem) noexcept;