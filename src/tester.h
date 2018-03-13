
#include "log.h"
#include "BitHackLogger/bithacklogger.h"

namespace bithack {
class Tester
{
private: 
	ILogger* m_logger;

public:
    Tester() {
    	m_logger = BitHackLogger::create();
    	Logger::setLogger(m_logger);
    }

    ~Tester() {
    	delete m_logger;
    }

    void run() {
        DEBUG("Hello Bithack");
    }

};

}

