#pragma once
#include <deque>
#include <vector>
#include <string>
#include <iostream>

#include "BookFactory.h"
#include "DequeToVectorAdapter.h"

class BookPool {
private:
    std::deque<Book> books;

public:
    Book takeBook();
    std::vector<Book> getBooks();
    bool contains(const std::string title);
    void returnBook(const Book& book);
};

