#include "ItemRepository.h"

#include "Item.h"

void ItemRepository::add_item(const Item &item) {
    total_quantities_+= item.quantity;
    items_[item.name] = item;
    const auto &categories_list = item.categories;

    for (int i = 0; i < categories_list.size(); i++) {
        categories_[item.categories[i]].total_quantity += item.quantity;
        categories_[item.categories[i]].items.push_back(item.name);

        if (i != 0) {
            categories_[item.categories[i]].sub_categories.insert(item.categories[i - 1]);
        }
    }
}

uint32_t ItemRepository::quantity_of_item(const std::string& item_name) const {
    auto it = items_.find(item_name);
    return it == items_.end() ? 0 : it->second.quantity;
}

uint32_t ItemRepository::count_of_items(const std::string& category_name) const {
    auto it = categories_.find(category_name);
    return it == categories_.end() ? 0 : static_cast<uint32_t>(it->second.items.size());
}

uint32_t ItemRepository::total_item_count() const noexcept {
    return static_cast<uint32_t>(items_.size());
}

uint32_t ItemRepository::total_item_quantity() const noexcept {
    return total_quantities_;
}

uint32_t ItemRepository::unique_item_count(const std::string& category_name) const {
    auto it = categories_.find(category_name);
    return it == categories_.end() ? 0 : static_cast<uint32_t>(it->second.items.size());
}

uint32_t ItemRepository::count_of_sub_categories(const std::string& category_name) const {
    auto it = categories_.find(category_name);
    return it == categories_.end() ? 0 : static_cast<uint32_t>(it->second.sub_categories.size());
}
