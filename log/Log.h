#ifndef LOG_H
#define LOG_H

#include <string>
#include <sstream>
#include <iostream>

const int MUTE = 0;
const int LOG = 1;
const int INFO = 2;
const int DEBUG = 3;

int LOGLEVEL = 0;

static const CODESTRING[4][] = {
	"",
	"LOG: ",
	"INFO: ",
	"VERBOSE: ",
	"DEBUG: "};

void log(int tag,string info)
{
	if(tag>LOGLEVEL)
		return;
	std::cout<<CODESTRING[tag]<<info<<std::endl;
}

#endif
