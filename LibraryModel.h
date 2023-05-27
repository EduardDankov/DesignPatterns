#pragma once
#include "LibraryFacade.h"

class LibraryModel {
private:
	LibraryFacade* facade;

public:
	LibraryModel();
	~LibraryModel();

    void createShelf(const std::string& shelfTitle);
    void deleteShelf(const std::string& shelfTitle);
    std::vector<Shelf> getShelves();

    void createBook(const std::string& title, const std::string& author, int pageCount);
    void deleteBook(const std::string& title, const std::string& author, int pageCount);
    void placeBook(const std::string& bookTitle, const std::string& shelfTitle);
    void moveBook(const std::string& bookTitle, const std::string& sourceTitle, const std::string& destinationTitle);
    void displaceBook(const std::string& bookTitle, const std::string& shelfTitle);
    std::vector<Book> getUnplacedBooks();

    void createReader(const std::string& readerName);
    void deleteReader(const std::string& readerName);
    std::vector<LibraryReader> getReaders();

    void subscribe(const std::string& readerName);
    void unsubscribe(const std::string& readerName);
};
