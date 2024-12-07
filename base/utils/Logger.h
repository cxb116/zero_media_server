//
// Created by cbb on 2024/11/27.
//

#ifndef ZERO_MEDIA_SERVER_LOGGER_H
#define ZERO_MEDIA_SERVER_LOGGER_H
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <thread>
#include <memory>
#include <mutex>
#include <string>
#include <iostream>
#include "List.h"
#include "Path.h"
#include "../thread/semaphore.h"
namespace zero
{

    class LogContext;
    class LogChannel;
    class LogWriter;
    class Logger;
    using LogContextPtr = std::shared_ptr<LogContext>;

    typedef enum {
        Trace = 0,
        Debug,
        Info,
        Ware,
        Error
    } LogLevel;

    Logger & getLogger();
    void setLogger(Logger *logger);


// 日志类
class Logger : public std::enable_shared_from_this<Logger> {
public:
   // friend class AsyncLogWriter;

    using Ptr = std::shared_ptr<Logger>;

    /**
     * 获取日志单例
     */
    static Logger &Instance();

    explicit Logger(const std::string &loggerName);

    ~Logger();

    /**
     * 添加日志通道非线程安全
     * @param channel  log通道
     */
    void add(const std::shared_ptr<LogChannel> &channel);

private:
    LogContextPtr last_log_;
    std::string logger_name_;
    std::shared_ptr<LogWriter> writer_;
    std::shared_ptr<LogChannel> default_channel_;
    std::map<std::string,std::shared_ptr<LogChannel>> channels_;


};

class LogContext : public std::ostringstream {
public:
    LogContext() = default;
    LogContext(LogLevel level,const char *file,const char* function,
               int line, const char *mudule_name,const char* flag);
    ~LogContext() = default;

    LogLevel level_;
    int line_;
    int repeat_ = 0;
    std::string file_;
    std::string function_;
    std::string thread_name_;
    std::string module_name_;
    std::string flag_;
    struct timeval tv_;

    const std::string &str();

private:
    bool got_content = false;
    std::string content_;
};

class LogChannel {
public:
    LogChannel(const std::string &name,LogLevel level = Trace);
    virtual ~LogChannel();

    virtual void write(const Logger &logger,const LogContextPtr &ctx) = 0;
    const std::string& name() const;
    void setLevel(LogLevel level);
//    static std::string printTime(const timeval &tv);
protected:
    std::string name_;
    LogLevel level_;
};

class ConsoleChannel :public LogChannel {
public:
    ConsoleChannel(const std::string &name = "ConsoleChannel",LogLevel  level = Trace);
    ~ConsoleChannel() override = default;

    void write(const Logger &logger,const LogContextPtr &logContext) override;
};


// 可重置默认值
extern Logger *g_defaultLogger;

//用法: DebugL << 1 << "+" << 2 << '=' << 3;  [AUTO-TRANSLATED:e6efe6cb]
//Usage: DebugL << 1 << "+" << 2 << '=' << 3;
#define WriteL(level) ::toolkit::LogContextCapture(::toolkit::getLogger(), level, __FILE__, __FUNCTION__, __LINE__)
#define TraceL WriteL(::toolkit::LTrace)
#define DebugL WriteL(::toolkit::LDebug)
#define InfoL WriteL(::toolkit::LInfo)
#define WarnL WriteL(::toolkit::LWarn)
#define ErrorL WriteL(::toolkit::LError)

//只能在虚继承BaseLogFlagInterface的类中使用  [AUTO-TRANSLATED:a395e54d]
//Can only be used in classes that virtually inherit from BaseLogFlagInterface
#define WriteF(level) ::toolkit::LogContextCapture(::toolkit::getLogger(), level, __FILE__, __FUNCTION__, __LINE__, getLogFlag())
#define TraceF WriteF(::toolkit::LTrace)
#define DebugF WriteF(::toolkit::LDebug)
#define InfoF WriteF(::toolkit::LInfo)
#define WarnF WriteF(::toolkit::LWarn)
#define ErrorF WriteF(::toolkit::LError)

//用法: PrintD("%d + %s = %c", 1 "2", 'c');  [AUTO-TRANSLATED:1217cc82]
//Usage: PrintD("%d + %s = %c", 1, "2", 'c');
#define PrintLog(level, ...) ::toolkit::LoggerWrapper::printLog(::toolkit::getLogger(), level, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define PrintT(...) PrintLog(::toolkit::LTrace, ##__VA_ARGS__)
#define PrintD(...) PrintLog(::toolkit::LDebug, ##__VA_ARGS__)
#define PrintI(...) PrintLog(::toolkit::LInfo, ##__VA_ARGS__)
#define PrintW(...) PrintLog(::toolkit::LWarn, ##__VA_ARGS__)
#define PrintE(...) PrintLog(::toolkit::LError, ##__VA_ARGS__)

//用法: LogD(1, "+", "2", '=', 3);  [AUTO-TRANSLATED:2a824fae]
//Usage: LogD(1, "+", "2", '=', 3);
//用于模板实例化的原因，如果每次打印参数个数和类型不一致，可能会导致二进制代码膨胀  [AUTO-TRANSLATED:c40b3f4e]
//Used for template instantiation, because if the number and type of print parameters are inconsistent each time, it may cause binary code bloat
#define LogL(level, ...) ::toolkit::LoggerWrapper::printLogArray(::toolkit::getLogger(), (LogLevel)level, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LogT(...) LogL(::toolkit::LTrace, ##__VA_ARGS__)
#define LogD(...) LogL(::toolkit::LDebug, ##__VA_ARGS__)
#define LogI(...) LogL(::toolkit::LInfo, ##__VA_ARGS__)
#define LogW(...) LogL(::toolkit::LWarn, ##__VA_ARGS__)
#define LogE(...) LogL(::toolkit::LError, ##__VA_ARGS__)
}


#endif //ZERO_MEDIA_SERVER_LOGGER_H
