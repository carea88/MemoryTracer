#pragma once
#include <string>
#include <map>

#ifdef STOCKMGR_EXPORT
#define STOCKMGR_API __declspec(dllexport)
#else
#define STOCKMGR_API __declspec(dllimport)
#endif

class STOCKMGR_API TracerItem
{
public:
	TracerItem(const std::string& fun/*, const std::string& line*/);
};

class STOCKMGR_API Tracer
{
public:
	static Tracer& Instance(void);
	struct StatisticsItem
	{
		int m_count = 0;
		int m_countDestroy = 0;
	};
	Tracer();
	~Tracer();
	void AddOneCount(const std::string& fun);
private:
	std::map<std::string, StatisticsItem>&  GetStatisticsMap(void);
private:
	std::map<std::string, StatisticsItem>  m_statisticsMap;
};

#define TRACE() TracerItem item(__FUNCTION__/*__FILE__*/);
