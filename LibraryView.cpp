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
		std::cout << "2. Place a book on a shelf" << std::endl;
		std::cout << "3. Replace a book on another shelf" << std::endl;
		std::cout << "4. Remove a book from a shelf" << std::endl;
		std::cout << "5. Display unplaced books list" << std::endl;
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

std::string LibraryView::getInput(const std::string& prompt) {
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}
