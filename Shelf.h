#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Book.h"

class Shelf {
private:
    std::string title;
    std::vector<Book> books;

public:
    Shelf(const std::string& title)
        : title(title) {}

    std::string getTitle();
    std::vector<Book>* getBooks();
    void addBook(const Book& book);
    void removeBook(const Book& book);
    void displayBooks() const;
};
