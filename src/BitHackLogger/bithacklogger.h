#ifndef SRC_BITHACKLOGGER_BITHACKLOGGER_H_
#define SRC_BITHACKLOGGER_BITHACKLOGGER_H_

#include "../ilogger.h"
#include "../loglevel.h"

class BitHackLogger 
{
public:
	static bithack::ILogger* create();
    virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
    virtual void setLevel(LogLevel level);
};

#endif /* SRC_BITHACKLOGGER_BITHACKLOGGER_H_ */
