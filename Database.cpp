#include "Database.h"

Database* Database::getInstance() {
    if (!instance) {
        instance = new Database();
    }
    return instance;
}

void Database::addShelf(Shelf& shelf) {
    for (auto& s : shelves) {
        if (s.getTitle() == shelf.getTitle()) {
            return throw "The shelf with such title already exists!";
        }
    }
    shelves.push_back(shelf);
}

void Database::displayShelves() {
    for (auto& shelf : shelves) {
        std::cout << "Shelf: " << shelf.getTitle() << " - " << (*shelf.getBooks()).size() << " book(s)" << std::endl;
        shelf.displayBooks();
    }
}

void Database::displayShelves(const std::string title) {
    std::cout << " === " << title << " === " << std::endl;
    displayShelves();
}

std::vector<Shelf>* Database::getShelves() {
    return &shelves;
}

void Database::addReader(LibraryReader& reader) {
    for (auto& r : readers) {
        if (r.getName() == reader.getName()) {
            return throw "The reader with such name already exists!";
        }
    }
    readers.push_back(reader);
}

void Database::displayReaders() {
    for (auto& reader : readers) {
        std::cout << reader.getName() << std::endl;
    }
}

void Database::displayReaders(const std::string title) {
    std::cout << " === " << title << " === " << std::endl;
    displayReaders();
}

std::vector<LibraryReader>* Database::getReaders() {
    return &readers;
}

Database* Database::instance = nullptr;
