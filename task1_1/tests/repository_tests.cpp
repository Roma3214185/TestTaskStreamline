#include <gtest/gtest.h>
#include "../ItemRepository.h"
#include "../utils.h"
#include "../Item.h"

class ItemRepositoryWithFiveItems : public ::testing::Test {
protected:
    ItemRepository repository;

    void SetUp() override {
        repository.add_item({
            .name{"item_23451"},
            .quantity = 150,
            .categories{utils::get_categories("Nike,T-shirts,Clothes")}
        });

        repository.add_item({
            .name{"item_23452"},
            .quantity = 75,
            .categories{utils::get_categories("Adidas,Hoodies,Clothes")}
        });

        repository.add_item({
            .name{"item_23453"},
            .quantity = 200,
            .categories{utils::get_categories("H&M,Dresses,Clothes")}
        });

        repository.add_item({
            .name{"item_23454"},
            .quantity = 120,
            .categories{utils::get_categories("Zara,Skirts,Clothes")}
        });

        repository.add_item({
            .name{"item_23455"},
            .quantity = 20,
            .categories{utils::get_categories("Timberland,Desert,Boots")}
        });
    }
};

TEST_F(ItemRepositoryWithFiveItems, TotalInItemCount) {
    EXPECT_EQ(repository.total_item_count(), 5);
}

TEST_F(ItemRepositoryWithFiveItems, AddItemTotalItemEquealSix) {
    Item new_item{
        .name{"item_23459"},
        .quantity = 150,
        .categories = {"TestCategory"}
    };

    repository.add_item(new_item);

    EXPECT_EQ(repository.total_item_count(), 6);
}

TEST_F(ItemRepositoryWithFiveItems, GetQuantityOfExistingItem) {
    EXPECT_EQ(repository.quantity_of_item("item_23451"), 150);
}

TEST_F(ItemRepositoryWithFiveItems, ItemsInClothes) {
    EXPECT_EQ(repository.unique_item_count("Clothes"), 4);
}

TEST_F(ItemRepositoryWithFiveItems, ItemsCountInCategorClothes) {
    EXPECT_EQ(repository.count_of_items("Clothes"), 545);
}

TEST_F(ItemRepositoryWithFiveItems, CountOfItemsInCategoryBoost) {
    EXPECT_EQ(repository.count_of_items("Boots"), 20);
}

TEST_F(ItemRepositoryWithFiveItems, CountOfItemsInCategorySkirts) {
    EXPECT_EQ(repository.count_of_items("Skirts"), 120);
}

TEST_F(ItemRepositoryWithFiveItems, AddSkirtsCountOfItemsInCategorySkirtsEqual140) {
    repository.add_item({
           .name{"item_23451"},
           .quantity = 20,
           .categories{utils::get_categories("Puma,Skirts,Clothes")}
       });

    EXPECT_EQ(repository.count_of_items("Skirts"), 120 + 20);
}

TEST_F(ItemRepositoryWithFiveItems, SubcategoriesOfClothesEqual4) {
    EXPECT_EQ(repository.count_of_sub_categories("Clothes"), 4);
}

TEST_F(ItemRepositoryWithFiveItems, SubcategoriesOfDressesEqual1) {
    EXPECT_EQ(repository.count_of_sub_categories("Dresses"), 1);
}

TEST_F(ItemRepositoryWithFiveItems, AddDressExpectedSubcategoriesOfDressesEqual2) {
    repository.add_item({
           .name{"item_234421"},
           .quantity = 23,
           .categories{utils::get_categories("Lewis,Dresses")}
       });
    EXPECT_EQ(repository.count_of_sub_categories("Dresses"), 2);
}

TEST_F(ItemRepositoryWithFiveItems, AddNewItemExpectedGivenQuantity) {
    constexpr int32_t expected_quantity = 1350;
    std::string item_name = "item_131441";

    repository.add_item({
           .name{item_name},
           .quantity = expected_quantity,
           .categories{utils::get_categories("Lewis,Dresses")}
       });

    EXPECT_EQ(repository.quantity_of_item(item_name), expected_quantity);
}

TEST_F(ItemRepositoryWithFiveItems, GetTotalItemQuantityExpected565) {
    EXPECT_EQ(repository.total_item_quantity(), 565);
}
