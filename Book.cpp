#include "Book.h"

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getPageCount() const {
    return pageCount;
}
