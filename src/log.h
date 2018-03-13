#ifndef LOG_H_
#define LOG_H_

#include "logger.h"
#include "loglevel.h"
#include <sstream>

#define DEBUG( text )  { \
    std::ostringstream stream; stream << text; \
    bithack::Logger::write(bithack::LOG_LEVEL_DEBUG, __FILE__, __LINE__, stream.str()); }

#define WARNING( text )  { \
    std::ostringstream stream; stream << text; \
    bithack::Logger::write(bithack::LOG_LEVEL_WARNING, __FILE__, __LINE__, stream.str()); }

#define ERROR( text )  { \
    std::ostringstream stream; stream << text; \
    bithack::Logger::write(bithack::LOG_LEVEL_ERROR, __FILE__, __LINE__, stream.str()); }

#endif /* LOG_H_ */

