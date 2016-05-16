#ifndef LOG_H
#define LOG_H

#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

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

public:
	Log(LogLevel lv=LogLevel::LOG):level(lv){}
	
	void i(LogLevel tag,string str)
	{
		if(tag==LogLevel::MUTE)
			return;
		if(static_cast<int>(tag) > static_cast<int>(level))
			return;
		cout<<CODESTRING[static_cast<int>(tag)]<<str<<endl;
	}
	void i(string tag,string str)
	{
		cout<<tag<<':'<<str<<endl;
	}
}log;

#endif
