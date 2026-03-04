#ifndef TEST_TASK_INDEXERROR_H
#define TEST_TASK_INDEXERROR_H

#include <string>
#include <stdexcept>

/// @brief Class implementing file exceptions
class IndexError : public std::exception {
public:
    explicit IndexError(size_t index, size_t size)
        : message_("IndexError: index " + std::to_string(index) +
                  " is out of bounds (size = " + std::to_string(size) + ")") {}

    /**
     * @brief Returns a pointer to the (constant) error description.
     *
     * @return A pointer to a const char*. The underlying memory
     *          is in posession of the Exception object. Callers must
     *          not attempt to free the memory.
     */
   [[nodiscard]] const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_; ///< Error message
};

#endif //TEST_TASK_INDEXERROR_H