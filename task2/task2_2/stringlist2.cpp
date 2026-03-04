#include "stringlist2.h"
#include "../IndexError.h"

CStrings2::CStrings2()
    : count_(0), capacity_(100), arData_(new std::string[capacity_]) {
}

CStrings2::~CStrings2() {
    delete[] arData_;
}

CStrings2::CStrings2(const CStrings2 &other)
    : count_(other.count_), capacity_(other.capacity()), arData_(new std::string[capacity_]) {
    for (size_t i = 0; i < count_; ++i)
        arData_[i] = other.arData_[i];
}

CStrings2 &CStrings2::operator=(const CStrings2 &other) {
    if (this == &other) return *this;

    delete[] arData_;
    capacity_ = other.capacity();
    count_ = other.count_;
    arData_ = new std::string[capacity_];

    for (size_t i = 0; i < count_; ++i)
        arData_[i] = other.arData_[i];

    return *this;
}

size_t CStrings2::size() const {
    return count_;
}

size_t CStrings2::capacity() const {
    return capacity_;
}

std::string &CStrings2::at(size_t idx) {
    if (idx >= count_)
        throw IndexError(idx, count_);
    return arData_[idx];
}

void CStrings2::add_elem(const std::string &element) {
    if (count_ == capacity_)
        resize(capacity_ * 2);

    arData_[count_++] = element;
}

void CStrings2::add_elem(std::string &&element) {
    if (count_ == capacity_)
        resize(capacity_ * 2);

    arData_[count_++] = std::move(element);
}

void CStrings2::erase(size_t idx) {
    if (idx >= count_) return;

    for (size_t j = idx; j + 1 < count_; ++j) {
        arData_[j] = arData_[j + 1];
    }

    --count_;
}

void CStrings2::resize(size_t new_capacity) {
    auto *newData = new std::string[new_capacity];

    for (size_t i = 0; i < count_; ++i)
        newData[i] = arData_[i];

    delete[] arData_;
    arData_ = newData;
    capacity_ = new_capacity;
}
