#pragma once
#include <deque>
#include <vector>

#include "Book.h"

template<typename T>
class DequeToVectorAdapter {
private:
    std::deque<T> deque_;

public:
    DequeToVectorAdapter(std::deque<T>& deque)
        : deque_(deque) {}

    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t index);
    size_t size() const;
    std::vector<T> toVector() const;
};
