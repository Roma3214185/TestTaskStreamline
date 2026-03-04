#include "utils.h"

#include <sstream>
#include <string>

namespace {
    std::string trim(const std::string& str) {
        auto start = std::find_if_not(str.begin(), str.end(),
                                      [](unsigned char ch){ return std::isspace(ch); });
        auto end = std::find_if_not(str.rbegin(), str.rend(),
                                    [](unsigned char ch){ return std::isspace(ch); }).base();
        if (start >= end) return "";
        return std::string(start, end);
    }
}

namespace utils {
    std::vector<std::string> get_categories(const std::string &json_categories) {
        auto categories = std::vector<std::string>{};

        std::stringstream ss(json_categories);
        std::string category;
        while (getline(ss, category, ',')) {
            if (auto trimmed_category = trim(category); !category.empty()) {
                categories.push_back(trimmed_category);
            }
        }
        return categories;
    }
}