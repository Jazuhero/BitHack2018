#include "bithacklogger.h"
#include "../loglevel.h"

using namespace bithack;

static ILogger* create()
{
	bithack::ILogger* logger = new bithack::ILogger;
	logger->setLevel(0);
	return logger;
}


ILogger::~ILogger()
{

}

void ILogger::write(LogLevel level, const char* file, uint32_t line, const std::string& text)
{

}

void ILogger::setLevel(LogLevel level)
{

}