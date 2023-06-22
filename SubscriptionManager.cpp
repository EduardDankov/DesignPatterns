#include "SubscriptionManager.h"

SubscriptionManager* SubscriptionManager::getInstance() {
    if (!instance) {
        instance = new SubscriptionManager();
    }
    return instance;
}

void SubscriptionManager::subscribe(LibraryReader* subscriber) {
    subscribers.push_back(subscriber);
}

void SubscriptionManager::unsubscribe(LibraryReader* subscriber) {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}

void SubscriptionManager::notify(const std::string& message) {
    for (const auto& subscriber : subscribers) {
        subscriber->notify("Library news: " + message);
    }
}

SubscriptionManager* SubscriptionManager::instance = nullptr;
