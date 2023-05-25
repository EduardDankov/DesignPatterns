#include "BookFactory.h"

Book BookFactory::createBook(const std::string& title, const std::string& author, const int pageCount)
{
	return Book(title, author, pageCount);
}
