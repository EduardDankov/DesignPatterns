#pragma once
#include "MoveStrategy.h"

class DisplaceMoveStrategy : public MoveStrategy {
public:
    void moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) override;
};
