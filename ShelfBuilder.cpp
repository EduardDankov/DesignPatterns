#include "ShelfBuilder.h"

ShelfBuilder& ShelfBuilder::addBook(const Book book) {
    shelf.addBook(book);
    return *this;
}

Shelf ShelfBuilder::build() {
    return shelf;
}
