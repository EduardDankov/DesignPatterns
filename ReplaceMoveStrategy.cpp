#include "ReplaceMoveStrategy.h"

void ReplaceMoveStrategy::moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) {
    sourceShelf.removeBook(book);
    destinationShelf.addBook(book);
}
