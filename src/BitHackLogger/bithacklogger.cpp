#include "bithacklogger.h"
#include "../loglevel.h"
#include <chrono>
#include <iostream>
#include <ctime>

using namespace bithack;

class MyLogger : public ILogger
{
public:
	virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
	virtual void setLevel(LogLevel level);
private:
	LogLevel level_;

};

void MyLogger::write(LogLevel level, const char* file, uint32_t line, const std::string& text)
{
	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cerr << std::ctime(&time) << std::endl;
}

void MyLogger::setLevel(LogLevel level)
{
	level_ = level;
}

ILogger* BitHackLogger::create()
{
	ILogger* logger = new MyLogger();
	logger->setLevel(LOG_LEVEL_DEFAULT);
	return logger;
}
