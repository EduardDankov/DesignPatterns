#include "PlaceMoveStrategy.h"

void PlaceMoveStrategy::moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) {
    destinationShelf.addBook(book);
}
