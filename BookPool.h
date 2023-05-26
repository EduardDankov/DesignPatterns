#pragma once
#include <deque>
#include <string>
#include <iostream>

#include "BookFactory.h"

class BookPool {
private:
    std::deque<Book> books;

public:
    Book getBook();
    bool contains(const std::string title);
    void returnBook(const Book& book);
    void displayBooks() const;
    void displayBooks(const std::string title) const;
};

