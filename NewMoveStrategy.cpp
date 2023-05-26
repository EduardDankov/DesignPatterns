#include "NewMoveStrategy.h"

void NewMoveStrategy::moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) {
    destinationShelf.addBook(book);
}
