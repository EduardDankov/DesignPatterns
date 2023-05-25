#include "LibraryReader.h"

std::string LibraryReader::getName() {
    return name;
}

void LibraryReader::notify(const std::string& message) {
    std::cout << "[" << name << "] " << message << std::endl;
}
