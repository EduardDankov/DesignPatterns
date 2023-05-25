#pragma once
#include "LibraryFacade.h"

class LibraryModel {
private:
	LibraryFacade* facade;

public:
	LibraryModel();
	~LibraryModel();

    void createShelf(const std::string& shelfTitle);
    void displayShelves() const;
    void displayShelves(const std::string& title) const;

    void createBook(const std::string& title, const std::string& author, int pageCount);
    void placeBook(const std::string& bookTitle, const std::string& shelfTitle);
    void moveBook(const std::string& bookTitle, const std::string& sourceTitle, const std::string& destinationTitle);

    void createReader(const std::string& readerName);
    void displayReaders() const;
    void displayReaders(const std::string& title) const;

    void subscribe(const std::string& readerName);
    void unsubscribe(const std::string& readerName);
};
