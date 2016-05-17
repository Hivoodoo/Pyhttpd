#ifndef LOG_H
#define LOG_H

#include <string>
#include <strstream>
#include <iostream>
#include <ctime>
#include <sys/time.h>	  

namespace{
	// using std::string;
	// using std::cout;
	// using std::endl;
	using namespace std;

	enum class LogLevel:int{
		MUTE=0,
		INFO,
		LOG,
		VERBOSE,
		DEBUG,
		NUM_T};

	static constexpr int CODELEN= static_cast<int>(LogLevel::NUM_T);
	static const string CODESTRING[]={
		"",
		"INFO: ",
		"LOG: ",
		"VERBOSE: ",
		"DEBUG: "};

	class Log
	{
		LogLevel level;
		string getTime()
		{
			struct timeval tv;
			gettimeofday(&tv,NULL);
			ostrstream os;
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
			

	public:
		Log(LogLevel lv=LogLevel::LOG):level(lv){}
		
		void i(LogLevel tag,string str)
		{
			if(tag==LogLevel::MUTE)
				return;
			if(static_cast<int>(tag) > static_cast<int>(level))
				return;
			cout<<getTime();
			cout<<CODESTRING[static_cast<int>(tag)];
			cout<<str<<endl;
		}
		void i(string tag,string str)
		{
			cout<<getTime();
			cout<<tag<<':'<<str<<endl;
		}
	}log;
}

#endif
