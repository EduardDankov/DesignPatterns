#include "LibraryFacade.h"

LibraryFacade::LibraryFacade() {
    database = Database::getInstance();
    librarian = Librarian::getInstance();
    pool = new BookPool();
    moveStrategy = nullptr;
}

LibraryFacade::~LibraryFacade() {
    delete pool;
    if (moveStrategy) delete moveStrategy;
}

void LibraryFacade::createShelf(const std::string& shelfTitle) {
    for (auto& shelf : *(database->getShelves())) {
        if (shelf.getTitle() == shelfTitle) {
            return throw "The shelf with such title already exists!";
        }
    }
    Shelf shelf = ShelfBuilder(shelfTitle).build();
    database->addShelf(shelf);
    librarian->notify("Added new shelf: " + shelfTitle);
}

void LibraryFacade::deleteShelf(const std::string& shelfTitle) {
    Shelf* deleteShelf = nullptr;
    for (auto& shelf : *(database->getShelves())) {
        if (shelf.getTitle() == shelfTitle) {
            deleteShelf = &shelf;
        }
    }
    if (deleteShelf) {
        for (auto& book : *(deleteShelf->getBooks())) {
            displaceBook(book.getTitle(), deleteShelf->getTitle());
        }
        database->removeShelf(*deleteShelf);
        librarian->notify("Removed the " + shelfTitle + " shelf");
    }
    else {
        throw "The shelf with such title doesn't exist!";
    }
}

std::vector<Shelf> LibraryFacade::getShelves() {
    return *database->getShelves();
}

void LibraryFacade::createBook(const std::string& title, const std::string& author, int pageCount) {
    Book book = BookFactory::createBook(title, author, pageCount);
    pool->returnBook(book);
    librarian->notify("Added new book: \"" + title + "\" by " + author);
}

void LibraryFacade::deleteBook(const std::string& title, const std::string& author, int pageCount) {
    Book bookToDelete = BookFactory::createBook(title, author, pageCount);

    if (pool->contains(title)) {
        while (true) {
            bookToDelete = pool->takeBook();
            if (bookToDelete.getTitle() != title) {
                pool->returnBook(bookToDelete);
            }
            else break;
        }
        
        if (bookToDelete.getAuthor() == author && bookToDelete.getPageCount() == pageCount) {
            librarian->notify("Book \"" + bookToDelete.getTitle() + "\" by " + bookToDelete.getAuthor() + " was removed from library");
        }
        else {
            throw "There is a book with such title but from different author or the different edition!";
        }
    }
    else {
        throw "The book with such name is on a shelf or doesn't exist at all!";
    }
}

void LibraryFacade::placeBook(const std::string& bookTitle, const std::string& shelfTitle) {
    Book bookToPlace = BookFactory::createBook("", "", -1);
    Shelf* destinationShelf = nullptr;

    for (auto& shelf : *database->getShelves()) {
        if (shelf.getTitle() == shelfTitle) {
            destinationShelf = &shelf;
            break;
        }
    }

    if (destinationShelf) {
        if (pool->contains(bookTitle)) {
            while (true) {
                bookToPlace = pool->takeBook();
                if (bookToPlace.getTitle() != bookTitle) {
                    pool->returnBook(bookToPlace);
                }
                else break;
            }

            if (moveStrategy) delete moveStrategy;
            moveStrategy = new PlaceMoveStrategy();

            moveStrategy->moveBook(bookToPlace, *destinationShelf, *destinationShelf);
            librarian->notify("Book \"" + bookToPlace.getTitle() + "\" by " + bookToPlace.getAuthor() + " was placed on \"" + shelfTitle + "\" shelf");
        }
        else {
            throw "Book to move not found.";
        }
    }
    else {
        throw "Destination shelf not found.";
    }
}

void LibraryFacade::moveBook(const std::string& bookTitle, const std::string& sourceTitle, const std::string& destinationTitle) {
    Book bookToMove = BookFactory::createBook("", "", -1);
    Shelf* sourceShelf = nullptr;
    Shelf* destinationShelf = nullptr;

    for (auto& shelf : *database->getShelves()) {
        if (shelf.getTitle() == sourceTitle) {
            sourceShelf = &shelf;
        }
        if (shelf.getTitle() == destinationTitle) {
            destinationShelf = &shelf;
        }
        if (sourceShelf && destinationShelf) {
            break;
        }
    }

    if (sourceShelf && destinationShelf) {
        for (auto& book : *sourceShelf->getBooks()) {
            if (book.getTitle() == bookTitle) {
                bookToMove = book;
                break;
            }
        }

        if (bookToMove.getPageCount() != -1) {
            if (moveStrategy) delete moveStrategy;
            moveStrategy = new ReplaceMoveStrategy();

            moveStrategy->moveBook(bookToMove, *sourceShelf, *destinationShelf);
            librarian->notify("Book \"" + bookToMove.getTitle() + "\" by " + bookToMove.getAuthor() + " was replaced on \"" + destinationTitle + "\" shelf");
        }
        else {
            throw "Book to move not found.";
        }
    }
    else {
        throw "Source shelf or destination shelf not found.";
    }
}

void LibraryFacade::displaceBook(const std::string& bookTitle, const std::string& shelfTitle) {
    Book bookToDisplace = BookFactory::createBook("", "", -1);
    Shelf* sourceShelf = nullptr;

    for (auto& shelf : *database->getShelves()) {
        if (shelf.getTitle() == shelfTitle) {
            sourceShelf = &shelf;
            break;
        }
    }

    if (sourceShelf) {
        for (auto& book : *sourceShelf->getBooks()) {
            if (book.getTitle() == bookTitle) {
                bookToDisplace = book;
            }
        }

        if (bookToDisplace.getPageCount() != -1) {
            if (moveStrategy) delete moveStrategy;
            moveStrategy = new DisplaceMoveStrategy();

            moveStrategy->moveBook(bookToDisplace, *sourceShelf, *sourceShelf);
            pool->returnBook(bookToDisplace);
            librarian->notify("Book \"" + bookToDisplace.getTitle() + "\" by " + bookToDisplace.getAuthor() + " was displaced from \"" + shelfTitle + "\" shelf");
        }
        else {
            throw "Book to move not found.";
        }
    }
    else {
        throw "Source shelf not found.";
    }
}

std::vector<Book> LibraryFacade::getUnplacedBooks() {
    return pool->getBooks();
}

void LibraryFacade::createReader(const std::string& readerName) {
    for (auto& reader : *(database->getReaders())) {
        if (reader.getName() == readerName) {
            return throw "The reader with such name already exists!";
        }
    }
    LibraryReader reader = LibraryReaderFactory::createLibrarySubscriber(readerName);
    database->addReader(reader);
}

void LibraryFacade::deleteReader(const std::string& readerName) {
    LibraryReader* deleteReader = nullptr;
    for (auto& reader : *(database->getReaders())) {
        if (reader.getName() == readerName) {
            deleteReader = &reader;
        }
    }
    if (deleteReader) {
        librarian->unsubscribe(deleteReader);
        database->removeReader(*deleteReader);
    }
    else {
        throw "The reader with such name doesn't exist!";
    }
}

std::vector<LibraryReader> LibraryFacade::getReaders() {
    return *database->getReaders();
}

void LibraryFacade::subscribe(const std::string& readerName) {
    LibraryReader* reader = nullptr;

    for (auto& subscriber : *database->getReaders()) {
        if (subscriber.getName() == readerName) {
            reader = &subscriber;
            break;
        }
    }

    if (reader) {
        librarian->subscribe(reader);
    }
    else {
        throw "Reader not found";
    }
}

void LibraryFacade::unsubscribe(const std::string& readerName) {
    LibraryReader* reader = nullptr;

    for (auto& subscriber : *database->getReaders()) {
        if (subscriber.getName() == readerName) {
            reader = &subscriber;
            break;
        }
    }

    if (reader) {
        librarian->unsubscribe(reader);
    }
    else {
        throw "Reader not found";
    }
}
