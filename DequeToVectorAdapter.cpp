#include "DequeToVectorAdapter.h"

template<typename T>
void DequeToVectorAdapter<T>::push_back(const T& value) {
    deque_.push_back(value);
}

template<typename T>
void DequeToVectorAdapter<T>::pop_back() {
    deque_.pop_back();
}

template<typename T>
T& DequeToVectorAdapter<T>::operator[](size_t index) {
    return deque_[index];
}

template<typename T>
size_t DequeToVectorAdapter<T>::size() const {
    return deque_.size();
}

template<typename T>
std::vector<T> DequeToVectorAdapter<T>::toVector() const {
    return std::vector<T>(deque_.begin(), deque_.end());
}

template class DequeToVectorAdapter<Book>;
