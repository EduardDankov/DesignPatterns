#include <iostream>

#include "LibraryFacade.h"

int main() {
	LibraryFacade library;

	library.createReader("Emily Johnson");
	library.createReader("John Smith");

	library.createShelf("Detective");
	library.subscribe("Emily Johnson");
	library.createShelf("Horror");

	library.createBook("IT", "Stephen King", 1138);
	library.subscribe("John Smith");
	library.createBook("The Lincoln Lawyer", "Michael Connelly", 404);

	library.placeBook("The Lincoln Lawyer", "Detective");
	library.placeBook("IT", "Detective");

	library.unsubscribe("Emily Johnson");
	library.moveBook("IT", "Detective", "Horror");

	library.displayShelves("Our books");
	library.displayReaders("Our readers");
	return 0;
}
