#include "bithacklogger.h"
#include "../loglevel.h"

using namespace bithack;

static ILogger* create()
{
	bithack::ILogger* logger = new MyLogger;
	logger->setLevel(0);
	return logger;
}

class MyLogger : public ILogger
{
public:
	virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
	virtual void setLevel(LogLevel level);
}

void MyLogger::write(LogLevel level, const char* file, uint32_t line, const std::string& text)
{

}

void MyLogger::setLevel(LogLevel level)
{

}
