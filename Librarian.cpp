#include "Librarian.h"

Librarian* Librarian::getInstance() {
    if (!instance) {
        instance = new Librarian();
    }
    return instance;
}

void Librarian::subscribe(LibraryReader* subscriber) {
    subscribers.push_back(subscriber);
}

void Librarian::unsubscribe(LibraryReader* subscriber) {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}

void Librarian::notify(const std::string& message) {
    for (const auto& subscriber : subscribers) {
        subscriber->notify("Library news: " + message);
    }
}

Librarian* Librarian::instance = nullptr;
