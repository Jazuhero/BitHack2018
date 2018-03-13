#ifndef ILOGGER_H
#define ILOGGER_H

#include "loglevel.h"
#include <string>
#include <stdint.h>

namespace bithack {

class ILogger {

public:
    virtual ~ILogger() {};
    virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text) = 0;
    virtual void setLevel(LogLevel level) = 0;
};

} // namespace bithack

#endif //ILOGGER_H
