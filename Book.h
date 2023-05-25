#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int pageCount;

public:
    Book(const std::string& title, const std::string& author, const int pageCount)
        : title(title), author(author), pageCount(pageCount) {}

    std::string getTitle() const;
    std::string getAuthor() const;
    int getPageCount() const;
};
