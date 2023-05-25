#pragma once
#include "MoveStrategy.h"

class ExistingMoveStrategy : public MoveStrategy {
public:
    void moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) override {
        sourceShelf.removeBook(book);
        destinationShelf.addBook(book);
    }
};
