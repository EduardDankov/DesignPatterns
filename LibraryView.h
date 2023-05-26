#pragma once
#include <string>

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
	std::string getInput(const std::string& prompt);
};

