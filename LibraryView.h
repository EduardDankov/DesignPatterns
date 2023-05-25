#pragma once
#include <string>

class LibraryView
{
public:
	void displayMenu();
	void displayConfirmation();
	void displayInputError();
	std::string getInput(const std::string& prompt);
};

