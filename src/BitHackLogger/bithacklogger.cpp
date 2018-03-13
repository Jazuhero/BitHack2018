#include "bithacklogger.h"
#include "../loglevel.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <thread>
#include <mutex>

//using namespace bithack;
namespace bithack {

class MyLogger : public ILogger
{
public:
	virtual void write(LogLevel level, const char* file, uint32_t line, const std::string& text);
	virtual void setLevel(LogLevel level);
private:
	LogLevel level_;
	std::mutex write_mtx;
	std::mutex level_mtx;

};

void MyLogger::write(LogLevel level, const char* file, uint32_t line, const std::string& text)
{
	if (level_ != LOG_LEVEL_DEFAULT and level_ != level) {
		return;
	}
	write_mtx.lock();

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

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//std::cerr << std::ctime(&time) << std::endl;

	std::string logMsg = std::ctime(&time);
	//logMsg = logMsg.substr(logMsg.size() - 1);
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

	//auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//std::cerr << std::ctime(&time) << std::endl;

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

} // namespace bithack

bithack::ILogger* BitHackLogger::create()
{
	bithack::ILogger* logger = new bithack::MyLogger();
	logger->setLevel(bithack::LOG_LEVEL_DEFAULT);
	return logger;
}


