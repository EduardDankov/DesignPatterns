#pragma once
#include "MoveStrategy.h"

class PlaceMoveStrategy : public MoveStrategy {
public:
    void moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) override;
};
