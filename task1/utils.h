#ifndef TEST_TASK_UTILS_H
#define TEST_TASK_UTILS_H

#include <vector>
#include <string>

namespace utils {
    /**
     * @brief Converts a comma-separated category string into a vector of strings.
     *
     * @example
     * "Nike,T-shirts,Clothes" → {"Nike", "T-shirts", "Clothes"}
     *
     * This is a helper function that can be used when parsing JSON or CSV input.
     *
     * @param json_categories A comma-separated category string.
     * @return A vector of individual categories ordered
     *         from the most specific (narrowest) to the most general (broadest).
     */
    std::vector<std::string> get_categories(const std::string &json_categories);

}; // namespace utils


#endif //TEST_TASK_UTILS_H