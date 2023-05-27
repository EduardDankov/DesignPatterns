#include <iostream>

#include "LibraryView.h"

void LibraryView::displayMenu() {
	std::cout << " === Library Menu === " << std::endl;
	std::cout << "1. Shelves" << std::endl;
	std::cout << "2. Books" << std::endl;
	std::cout << "3. Readers" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

void LibraryView::displayMenu(MenuSection section) {
	switch (section) {
	case Shelves:
		std::cout << " === Shelves Menu === " << std::endl;
		std::cout << "1. Create a shelf" << std::endl;
		std::cout << "2. Delete a shelf" << std::endl;
		std::cout << "3. Display shelves list" << std::endl;
		std::cout << "0. Exit" << std::endl;
		break;
	case Books:
		std::cout << " === Books Menu === " << std::endl;
		std::cout << "1. Create a book" << std::endl;
		std::cout << "2. Delete a book" << std::endl;
		std::cout << "3. Place a book on a shelf" << std::endl;
		std::cout << "4. Replace a book on another shelf" << std::endl;
		std::cout << "5. Remove a book from a shelf" << std::endl;
		std::cout << "6. Display unplaced books list" << std::endl;
		std::cout << "0. Exit" << std::endl;
		break;
	case Readers:
		std::cout << " === Readers Menu === " << std::endl;
		std::cout << "1. Create a library reader" << std::endl;
		std::cout << "2. Delete a library reader" << std::endl;
		std::cout << "3. Display library readers list" << std::endl;
		std::cout << "4. Subscribe a reader" << std::endl;
		std::cout << "5. Unsubscribe a reader" << std::endl;
		std::cout << "0. Exit" << std::endl;
		break;
	}
}

void LibraryView::displayConfirmation() {
	std::cout << "Done" << std::endl;
}

void LibraryView::displayInputError() {
	std::cout << "You entered invalid value!" << std::endl;
}

void LibraryView::displayShelves(std::vector<Shelf> shelves) {
	for (auto& shelf : shelves) {
		std::cout << "Shelf: " << shelf.getTitle() << " - " << (*shelf.getBooks()).size() << " book(s)" << std::endl;

		for (const auto& book : *shelf.getBooks()) {
			std::cout << "Title: \"" << book.getTitle() << "\", Author: " << book.getAuthor() << ", Page Count: " << book.getPageCount() << std::endl;
		}
	}
}

void LibraryView::displayShelves(std::vector<Shelf> shelves, const std::string title) {
	std::cout << " === " << title << " === " << std::endl;
	displayShelves(shelves);
}

void LibraryView::displayUnplacedBooks(std::vector<Book> books) const {
	for (const auto& book : books) {
		std::cout << "Title: \"" << book.getTitle() << "\", Author: " << book.getAuthor() << ", Page Count: " << book.getPageCount() << std::endl;
	}
}

void LibraryView::displayUnplacedBooks(std::vector<Book> books, const std::string title) const {
	std::cout << " === " << title << " === " << std::endl;
	displayUnplacedBooks(books);
}

void LibraryView::displayReaders(std::vector<LibraryReader> readers) {
	for (auto& reader : readers) {
		std::cout << reader.getName() << std::endl;
	}
}

void LibraryView::displayReaders(std::vector<LibraryReader> readers, const std::string title) {
	std::cout << " === " << title << " === " << std::endl;
	displayReaders(readers);
}

std::string LibraryView::getInput(const std::string& prompt) {
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}
