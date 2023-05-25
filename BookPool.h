#pragma once
#include <deque>
#include <string>

#include "BookFactory.h"

class BookPool {
private:
    std::deque<Book> books;

public:
    Book getBook();
    bool contains(const std::string title);
    void returnBook(const Book& book);
};

