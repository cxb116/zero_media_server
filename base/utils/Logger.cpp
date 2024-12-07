//
// Created by cbb on 2024/11/27.
//

#include "Logger.h"
#include <time.h>
#include <sys/time.h>
#include "Util.h"

namespace zero
{
    // 日志颜色以及对应的级别
static const char *LOG_CONST_TABLE[][3] = {
      {"\033[44;37m", "\033[34m", "T"},
      {"\033[42;37m", "\033[32m", "D"},
      {"\033[46;37m", "\033[36m", "I"},
      {"\033[43;37m", "\033[33m", "W"},
      {"\033[41;37m", "\033[31m", "E"}};


Logger *g_defaultLogger = nullptr;

Logger &getLogger() {
        if(!g_defaultLogger) {
            g_defaultLogger= &Logger::Instance();
        }
        return *g_defaultLogger;
    }

void setLogger(Logger *logger) {
        g_defaultLogger = logger;
    }

////////////////////////LogContext/////////////////////////////
INSTANCE_IMP(Logger,Path::exeName())

static inline const char* getFileName(const char* file) {


    auto pos = strrchr(file,'/');
        return pos ? pos + 1 : file;
}

static inline const char* getFunctionName(const char* func) {
    auto pos = strrchr(func,':');
    return pos ? pos + 1 : func;
}

LogContext::LogContext(LogLevel level,const char* file,const char* function,
                       int line,const char* module_name,const char* flag)
                      :level_(level),line_(line),file_(getFileName(file)),
                      function_(getFunctionName(function)),
                      module_name_(module_name),flag_(flag){
    gettimeofday(&tv_, nullptr);
    thread_name_ = getThreadName();

    std::cout<<"LogContext init \n";

}

const string &LogContext::str() {
    if(got_content) {
        return content_;
    }
    content_ = ostringstream::str();
    got_content = true;
    return content_;
}




//INSTANCE_IMP(Logger,exeName())

Logger::Logger(const std::string &loggerName) {
    logger_name_  = loggerName,
    last_log_ = std::make_shared<LogContext>();
    default_channel_ = std::make_shared<ConsoleChannel>("default",Trace);

    std::cout<<"Logger init \n";
}

Logger::~Logger() {

    std::cout<<"Logger destory\n";
}


void Logger::add(const std::shared_ptr<LogChannel> &channel) {
    channels_[channel->name()] = channel;
}



LogChannel::LogChannel(const std::string &name,LogLevel level )
    :name_(name),level_(level) {
    std::cout<<"name: "<<name_<< "level: "<<level_;
}

const std::string& LogChannel::name() const {
    return name_;
}

void LogChannel::setLevel(LogLevel level){ level_ = level;}

LogChannel::~LogChannel(){
    std::cout<<"LogChannel destroy \n";
}



ConsoleChannel::ConsoleChannel(const std::string &name, zero::LogLevel level) : LogChannel(name,level){
    std::cout<<"\n";
    std::cout<<"ConsoleChannel init()--------------------------------- \n";
}

void ConsoleChannel::write(const zero::Logger &logger, const LogContextPtr &logContext) {
    if(level_ > logContext->level_) {
        return;
    }

}


}



