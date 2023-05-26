#include "BookPool.h"

Book BookPool::getBook() {
    if (books.empty()) {
        throw "The pool is empty.";
    }
    else {
        Book& book = books.front();
        Book copy = BookFactory::createBook(book.getTitle(), book.getAuthor(), book.getPageCount());
        books.pop_front();
        return copy;
    }
}

bool BookPool::contains(const std::string title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            return true;
        }
    }
    return false;
}

void BookPool::returnBook(const Book& book) {
    books.push_back(book);
}

void BookPool::displayBooks() const {
    for (const auto& book : books) {
        std::cout << "Title: \"" << book.getTitle() << "\", Author: " << book.getAuthor() << ", Page Count: " << book.getPageCount() << std::endl;
    }
}

void BookPool::displayBooks(const std::string title) const {
    std::cout << " === " << title << " === " << std::endl;
    displayBooks();
}
