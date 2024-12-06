#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        for (const auto &row : matrix) {
            auto it = std::lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) return true;
        }
        return false;
    }
};


