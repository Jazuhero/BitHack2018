#include "bithacklogger.h"
#include "../loglevel.h"

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
