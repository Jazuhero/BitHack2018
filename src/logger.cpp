#include "logger.h"
#include "ilogger.h"
#include "assert.h"
namespace bithack {


namespace {
    bithack::ILogger* f_logger = 0;
}
namespace Logger {
    void setLogger(ILogger* logger)
    {
        f_logger = logger;
    }

    void write(LogLevel level, const char* file, uint32_t line, const std::string& text)
    {
        ASSERT(f_logger);
        f_logger->write(level,file,line,text);
    }
    void setLevel( LogLevel level)
    {
        ASSERT(f_logger);
        f_logger->setLevel(level);
    }
};

}
