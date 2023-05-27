#include "LibraryModel.h"

LibraryModel::LibraryModel() {
	facade = new LibraryFacade();
}

LibraryModel::~LibraryModel() {
	delete facade;
}

void LibraryModel::createShelf(const std::string& shelfTitle) {
	facade->createShelf(shelfTitle);
}

void LibraryModel::deleteShelf(const std::string& shelfTitle) {
	facade->deleteShelf(shelfTitle);
}

std::vector<Shelf> LibraryModel::getShelves() {
	return facade->getShelves();
}

void LibraryModel::createBook(const std::string& title, const std::string& author, int pageCount) {
	facade->createBook(title, author, pageCount);
}

void LibraryModel::deleteBook(const std::string& title, const std::string& author, int pageCount) {
	facade->deleteBook(title, author, pageCount);
}

void LibraryModel::placeBook(const std::string& bookTitle, const std::string& shelfTitle) {
	facade->placeBook(bookTitle, shelfTitle);
}

void LibraryModel::moveBook(const std::string& bookTitle, const std::string& sourceTitle, const std::string& destinationTitle) {
	facade->moveBook(bookTitle, sourceTitle, destinationTitle);
}

void LibraryModel::displaceBook(const std::string& bookTitle, const std::string& shelfTitle) {
	facade->displaceBook(bookTitle, shelfTitle);
}

std::vector<Book> LibraryModel::getUnplacedBooks() {
	return facade->getUnplacedBooks();
}

void LibraryModel::createReader(const std::string& readerName) {
	facade->createReader(readerName);
}

void LibraryModel::deleteReader(const std::string& readerName) {
	facade->deleteReader(readerName);
}

std::vector<LibraryReader> LibraryModel::getReaders() {
	return facade->getReaders();
}

void LibraryModel::subscribe(const std::string& readerName) {
	facade->subscribe(readerName);
}

void LibraryModel::unsubscribe(const std::string& readerName) {
	facade->unsubscribe(readerName);
}
