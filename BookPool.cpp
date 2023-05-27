#include "BookPool.h"

Book BookPool::takeBook() {
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

std::vector<Book> BookPool::getBooks() {
    return DequeToVectorAdapter<Book>(books).toVector();
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
