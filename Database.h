#pragma once
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "Shelf.h"
#include "LibraryReader.h"

class Database {
private:
    static Database* instance;
    std::vector<Shelf> shelves;
    std::vector<LibraryReader> readers;

    Database() {}

public:
    static Database* getInstance();

    void addShelf(Shelf& shelf);
    void removeShelf(Shelf& shelf);
    std::vector<Shelf>* getShelves();

    void addReader(LibraryReader& reader);
    void removeReader(LibraryReader& reader);
    std::vector<LibraryReader>* getReaders();
};
