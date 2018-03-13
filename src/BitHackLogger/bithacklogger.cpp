#include "bithacklogger.h"
#include "../loglevel.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <mutex>

using namespace bithack;

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

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cerr << std::ctime(&time) << std::endl;

	std::fstream log;
	log.open("tmp/debug.log", std::fstream::in | std::fstream::out | std::fstream::app);
	log << "tänne se mitä kirjoitetaan tiedostoon";
	log.close();

	write_mtx.unlock();
}

void MyLogger::setLevel(LogLevel level)
{
	level_mtx.lock();
	level_ = level;
	level_mtx.unlock();
}

ILogger* BitHackLogger::create()
{
	ILogger* logger = new MyLogger();
	logger->setLevel(LOG_LEVEL_DEFAULT);
	return logger;
}
