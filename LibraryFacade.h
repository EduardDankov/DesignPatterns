#pragma once
#include "Database.h"
#include "BookPool.h"
#include "ShelfBuilder.h"
#include "BookFactory.h"
#include "NewMoveStrategy.h"
#include "ExistingMoveStrategy.h"
#include "DisplaceMoveStrategy.h"
#include "Librarian.h"
#include "LibraryReaderFactory.h"

class LibraryFacade {
private:
    Database* database;
    Librarian* librarian;
    BookPool* pool;
    MoveStrategy* moveStrategy;

public:
    LibraryFacade();
    ~LibraryFacade();

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
