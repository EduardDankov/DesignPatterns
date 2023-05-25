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

void LibraryModel::displayShelves() const {
	facade->displayShelves();
}

void LibraryModel::displayShelves(const std::string& title) const {
	facade->displayShelves(title);
}

void LibraryModel::createBook(const std::string& title, const std::string& author, int pageCount) {
	facade->createBook(title, author, pageCount);
}

void LibraryModel::placeBook(const std::string& bookTitle, const std::string& shelfTitle) {
	facade->placeBook(bookTitle, shelfTitle);
}

void LibraryModel::moveBook(const std::string& bookTitle, const std::string& sourceTitle, const std::string& destinationTitle) {
	facade->moveBook(bookTitle, sourceTitle, destinationTitle);
}

void LibraryModel::createReader(const std::string& readerName) {
	facade->createReader(readerName);
}

void LibraryModel::displayReaders() const {
	facade->displayReaders();
}

void LibraryModel::displayReaders(const std::string& title) const {
	facade->displayReaders(title);
}

void LibraryModel::subscribe(const std::string& readerName) {
	facade->subscribe(readerName);
}

void LibraryModel::unsubscribe(const std::string& readerName) {
	facade->unsubscribe(readerName);
}
