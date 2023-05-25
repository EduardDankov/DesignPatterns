#include "LibraryReaderFactory.h"

LibraryReader LibraryReaderFactory::createLibrarySubscriber(const std::string& name)
{
	return LibraryReader(name);
}
