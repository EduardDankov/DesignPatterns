#pragma once
#include <vector>
#include <string>

#include "LibraryReader.h"

class Librarian
{
private:
    static Librarian* instance;
    std::vector<LibraryReader*> subscribers;

    Librarian() {}

public:
    static Librarian* getInstance();

    void subscribe(LibraryReader* subscriber);
    void unsubscribe(LibraryReader* subscriber);
    void notify(const std::string& message);
};
