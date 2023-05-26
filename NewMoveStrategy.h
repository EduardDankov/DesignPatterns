#pragma once
#include "MoveStrategy.h"
#include "BookPool.h"

class NewMoveStrategy : public MoveStrategy {
public:
    void moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) override;
};
