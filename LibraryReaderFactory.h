#pragma once
#include "LibraryReader.h"

class LibraryReaderFactory
{
public:
	static LibraryReader createLibrarySubscriber(const std::string& name);
};
