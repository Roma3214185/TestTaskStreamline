#ifndef TASK2_TASK2_3_H
#define TASK2_TASK2_3_H

#include <string>

template<typename T>
struct CArray2 {
    virtual ~CArray2() = default;

    [[nodiscard]] virtual size_t size() const = 0;

    [[nodiscard]] virtual T &at(size_t i) = 0;

    [[nodiscard]] virtual size_t capacity() const = 0;

    virtual void add_elem(const T &el) = 0;

    virtual void add_elem(T &&element) = 0;

    virtual void erase(size_t idx) = 0;
};

struct CStrings2 : CArray2<std::string> {
    CStrings2();

    ~CStrings2() override;

    CStrings2(const CStrings2 &other);

    CStrings2 &operator=(const CStrings2 &other);

    CStrings2(CStrings2 &&other) noexcept;

    CStrings2 &operator=(CStrings2 &&other) noexcept;

    size_t size() const override;

    size_t capacity() const override;

    std::string &at(size_t idx) override;

    void add_elem(const std::string &element) override;

    void add_elem(std::string &&element) override;

    void erase(size_t idx) override;

private:
    void resize(size_t new_capacity);

    size_t count_;
    size_t capacity_;
    std::string *arData_;
};
#endif //TASK2_TASK2_3_H
