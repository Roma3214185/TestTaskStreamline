#ifndef TEST_TASK_ITEM_H
#define TEST_TASK_ITEM_H

#include <string>
#include <vector>

/**
 * @brief Represents a warehouse item.
 */
struct Item {
    std::string name; ///< Unique item name.
    int32_t quantity{0}; ///< Quantity in stock (must be non-negative).
    std::vector<std::string> categories;  ///< Category hierarchy ordered from narrowest to broadest.
};

#endif // TEST_TASK_ITEM_H