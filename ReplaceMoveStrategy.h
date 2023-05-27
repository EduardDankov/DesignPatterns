#pragma once
#include "MoveStrategy.h"

class ReplaceMoveStrategy : public MoveStrategy {
public:
    void moveBook(const Book& book, Shelf& sourceShelf, Shelf& destinationShelf) override;
};
