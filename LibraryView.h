#pragma once
#include <vector>
#include <iostream>

#include "LibraryModel.h"

enum MenuSection {
	Exit,
	Shelves,
	Books,
	Readers
};

class LibraryView
{
public:
	void displayMenu();
	void displayMenu(MenuSection section);

	void displayConfirmation();
	void displayInputError();

	void displayShelves(std::vector<Shelf> shelves);
	void displayShelves(std::vector<Shelf> shelves, const std::string title);

	void displayReaders(std::vector<LibraryReader> readers);
	void displayReaders(std::vector<LibraryReader> readers, const std::string title);

	void displayUnplacedBooks(std::vector<Book> books) const;
	void displayUnplacedBooks(std::vector<Book> books, const std::string title) const;

	std::string getInput(const std::string& prompt);
};

