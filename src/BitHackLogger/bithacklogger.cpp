#include "bithacklogger.h"
#include "../loglevel.h"
#include <chrono>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iostream>

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
	std::string logLevelStr;

	switch (level)
	{
		case LOG_LEVEL_DEBUG:
		logLevelStr = "[DEBUG]";
		break;
		case LOG_LEVEL_WARNING:
		logLevelStr = "[WARNING]";
		break;
		case LOG_LEVEL_ERROR:
		logLevelStr = "[ERROR]";
		break;
		default:
		logLevelStr = "[DEFAULT]";
	}

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//std::cerr << std::ctime(&time) << std::endl;

	std::string logMsg = std::ctime(&time);
	//logMsg = logMsg.substr(logMsg.size() - 1);
	logMsg += " ";
	logMsg += file;
	logMsg += " ";
	logMsg += std::to_string(line);
	logMsg += " ";
	logMsg += logLevelStr;
	logMsg += " ";
	logMsg += text;

	logMsg.erase(std::remove(logMsg.begin(), logMsg.end(), '\n'), logMsg.end());

	std::cout << logMsg << std::endl;

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
