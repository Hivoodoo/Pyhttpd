#ifndef SERVEREXCEPTION_H
#define SERVEREXCEPTION_H

// for exception
#include <exception>
#include <string>

class ServerException:public exception;
{
	int mErrorCode;
public:
	const char* what()const throw();
	ServerException(int code);
}
