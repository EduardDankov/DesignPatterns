#pragma once
#include "LibraryReader.h"

class LibraryReaderFactory
{
public:
	static LibraryReader createLibraryReader(const std::string& name);
};
