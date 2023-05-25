#pragma once
#include "Shelf.h"

class ShelfBuilder {
private:
    Shelf shelf;

public:
    ShelfBuilder(const std::string& title)
        : shelf(Shelf(title)) {}

    ShelfBuilder& addBook(const Book book);
    Shelf build();
};
