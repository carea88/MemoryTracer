#include "Tracer.h"
#include <iostream>

TracerItem::TracerItem(const std::string& fun/*, const std::string& line*/)
{
	Tracer::Instance().AddOneCount(fun);
}

Tracer & Tracer::Instance(void)
{
	static Tracer s_instance;
	return s_instance;
}

Tracer::Tracer()
{
}


Tracer::~Tracer()
{
	for (auto itr : m_statisticsMap)
	{
		std::cout << itr.first << " " << itr.second.m_count<< " ";
		if (itr.second.m_countDestroy >= 0)
		{
			std::cout << "~" << itr.first << " " << itr.second.m_countDestroy;
			auto leakCount = itr.second.m_count - itr.second.m_countDestroy;
			if (leakCount > 0)
			{
				std::cout << " >>>>>>>>>>>>>>>>>>>>>>>leak:"<<leakCount;
			}
		}
		std::cout << "\n";
	}
}

std::map<std::string, Tracer::StatisticsItem>&  Tracer::GetStatisticsMap(void)
{
	return m_statisticsMap;
}

void Tracer::AddOneCount(const std::string& fun)
{
	auto& statistics = GetStatisticsMap();
	auto itr = fun.find('~');
	
	if (itr != std::string::npos)
	{
		auto fun1 = fun;
		fun1.erase(itr,1);
		statistics[fun1].m_countDestroy++;
	}
	else
	{
		statistics[fun].m_count++;
	}
}
