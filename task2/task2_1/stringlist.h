#pragma once
#include <string>

template<typename T>
struct CArray {
    CArray();

    ~CArray();

    CArray(const CArray &other);

    CArray &operator=(const CArray &other);

    size_t size() const;

    size_t capacity() const;

    T &sAt(size_t idx);

    const T &sAt(size_t idx) const;

    void add_elem(const T &element);

    void add_elem(T &&element);

    void erase(size_t idx);

private:
    void resize(size_t new_capacity);

    size_t count_;
    size_t capacity_;
    T *arData_;
};

using CStrings = CArray<std::string>; //class CStrings : public CArray<CString> {}

#include "stringlist.inl"
