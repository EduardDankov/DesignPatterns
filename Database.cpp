#include "Database.h"

Database* Database::getInstance() {
    if (!instance) {
        instance = new Database();
    }
    return instance;
}

void Database::addShelf(Shelf& shelf) {
    shelves.push_back(shelf);
}

void Database::removeShelf(Shelf& shelf) {
    shelves.erase(std::remove(shelves.begin(), shelves.end(), shelf), shelves.end());
}

std::vector<Shelf>* Database::getShelves() {
    return &shelves;
}

void Database::addReader(LibraryReader& reader) {
    readers.push_back(reader);
}

void Database::removeReader(LibraryReader& reader) {
    readers.erase(std::remove(readers.begin(), readers.end(), reader), readers.end());
}

std::vector<LibraryReader>* Database::getReaders() {
    return &readers;
}

Database* Database::instance = nullptr;
