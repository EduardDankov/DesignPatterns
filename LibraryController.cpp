#include "LibraryController.h"

LibraryController::LibraryController() {
	model = new LibraryModel();
	view = new LibraryView();
}

LibraryController::~LibraryController() {
	delete model;
	delete view;
}

void LibraryController::run() {
	bool exit = false;

	while (!exit) {
		view->displayMenu();
		std::string choice = view->getInput("Write an index: ");

		try {
			int index = atoi(choice.c_str());
			if (index < 0 && index > 9) {
				throw "Invalid index!";
			}
			if (index == 0) {
				exit = true;
			}
			else {
				run(index);
			}
		}
		catch (...) {
			view->displayInputError();
		}
	}
}

void LibraryController::run(int index) {
	try {
		switch (index) {
			// createShelf
			case 1: {
				std::string shelfTitle = view->getInput("Shelf title: ");
				if (shelfTitle.length() <= 0) {
					throw "Invalid input!";
				}
				model->createShelf(shelfTitle);
				view->displayConfirmation();
				break;
			}
			// displayShelves
			case 2: {
				std::string title = view->getInput("Output title. You may leave it empty: ");
				if (title.length() != 0) {
					model->displayShelves(title);
				}
				else {
					model->displayShelves();
				}
				view->displayConfirmation();
				break;
			}
			// createBook
			case 3: {
				std::string title = view->getInput("Book title: ");
				std::string author = view->getInput("Book author: ");
				std::string pageCountString = view->getInput("Page count: ");
				if (title.length() <= 0 || author.length() <= 0 || pageCountString.length() <= 0) {
					throw "Invalid input!";
				}
				int pageCount = atoi(pageCountString.c_str());
				model->createBook(title, author, pageCount);
				view->displayConfirmation();
				break;
			}
			// placeBook
			case 4: {
				std::string bookTitle = view->getInput("Book title: ");
				std::string shelfTitle = view->getInput("Shelf title: ");
				if (bookTitle.length() <= 0 || shelfTitle.length() <= 0) {
					throw "Invalid input!";
				}
				model->placeBook(bookTitle, shelfTitle);
				view->displayConfirmation();
				break;
			}
			// moveBook
			case 5: {
				std::string bookTitle = view->getInput("Book title: ");
				std::string sourceTitle = view->getInput("Source shelf title: ");
				std::string destinationTitle = view->getInput("Destination shelf title: ");
				if (bookTitle.length() <= 0 || sourceTitle.length() <= 0 || destinationTitle.length() <= 0) {
					throw "Invalid input!";
				}
				model->moveBook(bookTitle, sourceTitle, destinationTitle);
				view->displayConfirmation();
				break;
			}
			// createReader
			case 6: {
				std::string readerName = view->getInput("Reader name: ");
				if (readerName.length() <= 0) {
					throw "Invalid input!";
				}
				model->createReader(readerName);
				view->displayConfirmation();
				break;
			}
			// displayReaders
			case 7: {
				std::string title = view->getInput("Output title. You may leave it empty: ");
				if (title.length() != 0) {
					model->displayReaders(title);
				}
				else {
					model->displayReaders();
				}
				view->displayConfirmation();
				break;
			}
			// subscribe
			case 8: {
				std::string readerName = view->getInput("Reader name: ");
				if (readerName.length() <= 0) {
					throw "Invalid input!";
				}
				model->subscribe(readerName);
				view->displayConfirmation();
				break;
			}
			// unsubscribe
			case 9: {
				std::string readerName = view->getInput("Reader name: ");
				if (readerName.length() <= 0) {
					throw "Invalid input!";
				}
				model->unsubscribe(readerName);
				view->displayConfirmation();
				break;
			}
		}
	}
	catch (...) {
		view->displayInputError();
	}
}
