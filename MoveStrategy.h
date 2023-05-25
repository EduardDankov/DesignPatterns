#pragma once
#include "Book.h"
#include "Shelf.h"

class MoveStrategy {
public:
    virtual void moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) = 0;
};
