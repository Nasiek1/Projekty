#include "FileNotFoundException.h"


const char* FileNotFoundException::what() const noexcept
{
	return "File wasn't found";
}
FileNotFoundException::FileNotFoundException()
{
}


FileNotFoundException::~FileNotFoundException()
{
}
