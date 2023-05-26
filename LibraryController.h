#pragma once
#include "LibraryModel.h"
#include "LibraryView.h"

class LibraryController {
private:
	LibraryModel* model;
	LibraryView* view;

public:
	LibraryController();
	~LibraryController();

	void run();
	void run(MenuSection section);
	void run(MenuSection section, int index);
};

