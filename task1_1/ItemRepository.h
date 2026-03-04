#ifndef TEST_TASK_ITEMREPOSITORY_H
#define TEST_TASK_ITEMREPOSITORY_H

#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

struct Item;

/**
 * @brief In-memory repository for managing warehouse items grouped by categories.
 *
 * The repository stores items by name and maintains aggregated statistics:
 * - total quantity of all items,
 * - per-category quantity (including nested subcategories),
 * - number of unique items per category,
 * - category hierarchy information.
 *
 * @note This class is not thread-safe.
 */
class ItemRepository {
public:

    /**
     * @brief Adds an item to the repository.
     *
     * After insertion:
     * - the item is stored in the internal item map;
     * - the global total quantity is updated;
     * - corresponding category statistics are updated.
     *
     * @param item Item instance to be added.
     *
     * @warning Behavior is implementation-defined if an item with the same
     * name already exists (overwrite / ignore / throw).
     *
     * @complexity Average O(1)
     */
    void add_item(const Item& item);

    /**
     * @brief Returns the quantity of the specified item.
     *
     * @param item_name Name of the item.
     * @return Quantity in stock, or 0 if the item does not exist.
     *
     * @complexity Average O(1)
     */
    uint32_t quantity_of_item(const std::string& item_name) const;

    /**
     * @brief Returns the total quantity of items within a category.
     *
     * The result includes all nested subcategories.
     *
     * @param category_name Name of the category.
     * @return Aggregated quantity of items in the category.
     *
     */
    uint32_t count_of_items(const std::string& category_name) const;

    /**
     * @brief Returns the total count of all items in the repository.
     *
     * @return Global items count.
     *
     * @complexity O(1)
     */
    uint32_t total_item_count() const noexcept;

    /**
     * @brief Returns the total quantity of all items in the repository.
     *
     * @return Global aggregated quantity.
     *
     * @complexity O(1)
     */
    uint32_t total_item_quantity() const noexcept;

    /**
     * @brief Returns the number of unique items in a category.
     *
     * Uniqueness is determined by item name.
     * Item quantities are not considered.
     *
     * @param category_name Name of the category.
     * @complexity O(1) in average
     * @return Number of distinct item names in the category.
     */
    uint32_t unique_item_count(const std::string& category_name) const;

    /**
     * @brief Returns the number of direct subcategories.
     *
     * @param category_name Name of the category.
     * @complexity O(1) in average
     * @return Number of immediate child categories.
     */
    uint32_t count_of_sub_categories(const std::string& category_name) const;

private:

    /**
     * @brief Internal representation of a category node.
     *
     * Invariants:
     * - total_quantity reflects aggregated quantity of this category,
     *   including all nested subcategories;
     * - sub_categories contains only direct child categories;
     * - items stores names of items assigned to this category.
     */
    struct Category {
        std::string name;
        uint32_t total_quantity{0};
        std::unordered_set<std::string> sub_categories;
        std::vector<std::string> items;
    };

    uint32_t total_quantities_{0}; ///! Global quantities of all items (must be always nonegative)

    /// Map: category name -> category node
    std::unordered_map<std::string, Category> categories_;

    /// Map: item name -> item object
    std::unordered_map<std::string, Item> items_;
};

#endif // TEST_TASK_ITEMREPOSITORY_H