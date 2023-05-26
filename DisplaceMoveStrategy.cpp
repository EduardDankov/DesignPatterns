#include "DisplaceMoveStrategy.h"

void DisplaceMoveStrategy::moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) {
    sourceShelf.removeBook(book);
}
