#ifndef LOGGER_H
#define LOGGER_H

#include "loglevel.h"
#include "ilogger.h"

namespace bithack {

namespace Logger {
    void setLogger(ILogger* logger);
    void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
    void setLevel( LogLevel level);
};

}

#endif //LOGGER_H

