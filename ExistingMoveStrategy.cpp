#include "ExistingMoveStrategy.h"

void ExistingMoveStrategy::moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) {
    sourceShelf.removeBook(book);
    destinationShelf.addBook(book);
}
