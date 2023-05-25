#pragma once
#include "Book.h"

class BookFactory
{
public:
	static Book createBook(const std::string& title, const std::string& author, const int pageCount);
};
