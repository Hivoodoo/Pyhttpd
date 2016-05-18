#include "ServerException.h"

ServerException::ServerException(int code)
{
}

ServerException::const char* what()const throw()
{
	return "ERROR!"
}
