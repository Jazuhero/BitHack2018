#include "bithacklogger.h"
#include "../loglevel.h"

#include <iostream>

using namespace bithack;

class MyLogger : public ILogger
{
public:
	virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
	virtual void setLevel(LogLevel level);
};

void MyLogger::write(LogLevel level, const char* file, uint32_t line, const std::string& text)
{
	std::string logMsg = "<DATETIME>";
	logMsg += " ";
	logMsg += file;
	logMsg += " ";
	logMsg += line;
	logMsg += " ";
	logMsg += text;

	std::cout << logMsg << std::endl;
}

void MyLogger::setLevel(LogLevel level)
{

}

ILogger* BitHackLogger::create()
{
	ILogger* logger = new MyLogger();
	logger->setLevel(LogLevel::LOG_LEVEL_DEFAULT);
	return logger;
}