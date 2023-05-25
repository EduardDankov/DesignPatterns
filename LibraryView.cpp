#include <iostream>

#include "LibraryView.h"

void LibraryView::displayMenu() {
	std::cout << " === Library Menu === " << std::endl;
	std::cout << "1. Create a shelf" << std::endl;
	std::cout << "2. Display shelves list" << std::endl;
	std::cout << "3. Create a book" << std::endl;
	std::cout << "4. Place a book on a shelf" << std::endl;
	std::cout << "5. Replace a book on another shelf" << std::endl;
	std::cout << "6. Create a library reader" << std::endl;
	std::cout << "7. Display library readers list" << std::endl;
	std::cout << "8. Subscribe a reader" << std::endl;
	std::cout << "9. Unsubscribe a reader" << std::endl;
	std::cout << "0. Exit" << std::endl;
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
