#include "Tracer2.h"
#include "../../MemoryTracer/Tracer.h"
//
//
//Tracer::Tracer()
//{
//}
//
//
//Tracer::~Tracer()
//{
//}
void * operator new(size_t size)
{
	//TRACE();
	auto cc = __FILE__;
	/*std::string s(*/__FILE__/*)*/;
	//s += (__FUNCTION__);
	//std::cout << s << "\n";
	if (void* mem = malloc(size))
	{
		return mem;
	}
	else
	{
		throw std::bad_alloc();
	}
}

void operator delete(void* mem) noexcept
{
	//TRACE();
	free(mem);
}