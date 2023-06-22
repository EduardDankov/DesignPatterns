#pragma once
#include <vector>
#include <string>
#include <algorithm>

#include "LibraryReader.h"

class SubscriptionManager
{
private:
    static SubscriptionManager* instance;
    std::vector<LibraryReader*> subscribers;

    SubscriptionManager() {}

public:
    static SubscriptionManager* getInstance();

    void subscribe(LibraryReader* subscriber);
    void unsubscribe(LibraryReader* subscriber);
    void notify(const std::string& message);
};
