#ifndef LOG_H
#define LOG_H

#include <string>

namespace Log
{

enum class LogLevel:int{
    kMUTE = 0,
    kINFO,
    kLOG,
    kVERBOSE,
    kDEBUG,
    kNUM_T
};

static const std::string kCODESTRING[]={
    "",
    "INFO: ",
    "LOG: ",
    "VERBOSE: ",
    "DEBUG: "
};

static constexpr int kCODELEN = static_cast<int>(LogLevel::kNUM_T);

class Logger
{
 public:
  static void i(LogLevel level, std::string context);
  static void i(std::string level, std::string context);

  static void level(LogLevel level) { level_ = level;}
  static LogLevel GetLevel() { return level_;}

 private:
  Logger(){};
  // ATTENTION: set before use!
  // TODO: set in logger.cc
  static LogLevel level_;

  static std::string GetTime();
};

}// namespace log

#endif
