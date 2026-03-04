#include "stringlist.h"
#include "../IndexError.h"

template <typename T>
CArray<T>::CArray()
    : count_(0), capacity_(100), arData_(new T[capacity_]) {}

template <typename T>
CArray<T>::~CArray() {
    delete[] arData_;
}

template <typename T>
CArray<T>::CArray(const CArray& other)
    : count_(other.count_), capacity_(other.capacity()), arData_(new T[capacity_]) {
    for (size_t i = 0; i < count_; ++i)
        arData_[i] = other.arData_[i];
}

template <typename T>
CArray<T>& CArray<T>::operator=(const CArray& other) {
    if (this == &other) return *this;

    delete[] arData_;
    capacity_ = other.capacity();
    count_ = other.count_;
    arData_ = new T[capacity_];

    for (size_t i = 0; i < count_; ++i)
        arData_[i] = other.arData_[i];

    return *this;
}

template <typename T>
size_t CArray<T>::size() const {
    return count_;
}

template <typename T>
size_t CArray<T>::capacity() const {
    return capacity_;
}

template <typename T>
T& CArray<T>::sAt(size_t idx) {
    if (idx >= count_)
        throw IndexError(idx, count_);
    return arData_[idx];
}

template <typename T>
const T& CArray<T>::sAt(size_t idx) const {
    if (idx >= count_)
        throw IndexError(idx, count_);

    return arData_[idx];
}

template <typename T>
void CArray<T>::add_elem(const T& element) {
    if (count_ == capacity_)
        resize(capacity_ * 2);
    arData_[count_++] = element;
}

template <typename T>
void CArray<T>::add_elem(T&& element) {
    if (count_ == capacity_)
        resize(capacity_ * 2);
    arData_[count_++] = std::move(element);
}

template <typename T>
void CArray<T>::erase(size_t idx) {
    if (idx >= count_) return;

    for (size_t j = idx; j + 1 < count_; ++j) {
        arData_[j] = arData_[j + 1];
    }

    --count_;
}

template <typename T>
void CArray<T>::resize(size_t new_capacity) {
    auto * newData = new T[new_capacity];

    for (size_t i = 0; i < count_; ++i)
        newData[i] = arData_[i];

    delete[] arData_;
    arData_ = newData;
    capacity_ = new_capacity;
}