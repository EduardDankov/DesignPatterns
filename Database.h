#pragma once
#include <string>
#include <vector>
#include <string>
#include <iostream>

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

    void addShelf(const Shelf& shelf);
    void displayShelves();
    void displayShelves(const std::string title);
    std::vector<Shelf>* getShelves();

    void addReader(const LibraryReader& shelf);
    void displayReaders();
    void displayReaders(const std::string title);
    std::vector<LibraryReader>* getReaders();
};
