#ifndef SRC_BITHACKLOGGER_BITHACKLOGGER_H_
#define SRC_BITHACKLOGGER_BITHACKLOGGER_H_

#include "../ilogger.h"
#include "../loglevel.h"

class BitHackLogger 
{
public:
	static bithack::ILogger* create();
};

#endif /* SRC_BITHACKLOGGER_BITHACKLOGGER_H_ */
