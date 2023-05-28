#include "LibraryReaderFactory.h"

LibraryReader LibraryReaderFactory::createLibraryReader(const std::string& name)
{
	return LibraryReader(name);
}
