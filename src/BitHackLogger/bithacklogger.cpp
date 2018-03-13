#include "bithacklogger.h"


static bithack::ILogger* create()
{
	bithack::ILogger* logger = new bithack::ILogger;
	return logger;
}
