#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>    

#include "logger.h"

std::string Log::Logger::GetTime()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  std::stringstream os;
  time_t now;
  now = time(NULL);//获取当前时间

  struct tm *t;
  t = localtime(&now);//转换为tm

  os<<"[";
  os<<t->tm_year+1900<<'.';
  os<<t->tm_mon+1<<'.';
  os<<t->tm_mday<<' ';
  os<<t->tm_hour<<':';
  os<<t->tm_min<<':';
  os<<t->tm_sec<<':';
  os<<tv.tv_usec<<"] ";
  return os.str();
}


void Log::Logger::i(LogLevel tag, std::string str)
{
  using std::cout;
  using std::endl;

  if(tag == LogLevel::kMUTE)
    return;
  if(static_cast<int>(tag) > static_cast<int>(Logger::level_))
    return;
  std::cout<<GetTime();
  cout<<kCODESTRING[static_cast<int>(tag)];
  cout<<str<<endl;
}

void Log::Logger::i(std::string tag, std::string str)
{
  using std::cout;
  using std::endl;

  cout<<GetTime();
  cout<<tag<<':'<<str<<endl;
}

Log::Logger::level(Log::LogLevel::kINFO);
