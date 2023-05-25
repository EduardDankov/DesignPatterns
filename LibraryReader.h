#pragma once
#include <string>
#include <iostream>

class LibraryReader {
private:
    std::string name;

public:
    LibraryReader(std::string name) 
        : name(name) {}

    std::string getName();
    void notify(const std::string& message);
};
