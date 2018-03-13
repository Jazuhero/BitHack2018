#include "bithacklogger.h"
#include "../loglevel.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>

//using namespace bithack;
namespace bithack {
namespace myspace {
std::mutex write_mtx;
std::mutex level_mtx;

class MyLogger : public ILogger
{
public:
	virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
	virtual void setLevel(LogLevel level);
private:
	LogLevel level_;
};

void MyLogger::write(LogLevel level, const char* file, uint32_t line, const std::string& text)
{
	if (level_ != LOG_LEVEL_DEFAULT and level_ <= level) {
		return;
	}

	std::string logLevelStr;

	switch (level)
	{
		case LOG_LEVEL_DEBUG:
		logLevelStr = "[DEBUG]";
		break;
		case LOG_LEVEL_WARNING:
		logLevelStr = "[WARNING]";
		break;
		case LOG_LEVEL_ERROR:
		logLevelStr = "[ERROR]";
		break;
		default:
		logLevelStr = "[DEFAULT]";
	}

	write_mtx.lock();

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::tm *ltm = std::localtime(&time);

	std::string logMsg = std::to_string(1900 + ltm->tm_year);
	logMsg += "-";
	if (1 + ltm->tm_mon >= 10)
	{
		logMsg += std::to_string(1 + ltm->tm_mon);
	}
	else
	{
		logMsg += "0";
		logMsg += std::to_string(1 + ltm->tm_mon);
	}
	logMsg += "-";
	logMsg += std::to_string(ltm->tm_mday);
	logMsg += " ";
	logMsg += std::to_string(ltm->tm_hour);
	logMsg += ":";
	logMsg += std::to_string(1 + ltm->tm_min);
	logMsg += ":";
	if (1 + ltm->tm_sec >= 10)
	{
		logMsg += std::to_string(1 + ltm->tm_sec);
	}
	else
	{
		logMsg += "0";
		logMsg += std::to_string(1 + ltm->tm_sec);
	}
	logMsg += " ";
	logMsg += file;
	logMsg += " ";
	logMsg += std::to_string(line);
	logMsg += " ";
	logMsg += logLevelStr;
	logMsg += " ";
	logMsg += text;

	logMsg.erase(std::remove(logMsg.begin(), logMsg.end(), '\n'), logMsg.end());

	std::cout << logMsg << std::endl;

	// The tmp-folder must exist before this!!
	std::fstream log;
	log.open("tmp/debug.log", std::fstream::in | std::fstream::out | std::fstream::app);
	log << logMsg;
	log.close();

	write_mtx.unlock();
}

void MyLogger::setLevel(LogLevel level)
{
	level_mtx.lock();
	level_ = level;
	level_mtx.unlock();
}

} // namespace myspace
} // namespace bithack

bithack::ILogger* BitHackLogger::create()
{
	bithack::ILogger* logger = new bithack::myspace::MyLogger();
	logger->setLevel(bithack::LOG_LEVEL_DEFAULT);
	return logger;
}


