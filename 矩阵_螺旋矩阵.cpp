#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> vec;
        int u = 0;
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true) {
            for (int i = l; i <= r; i++) vec.push_back(matrix[u][i]);
            if (++u > d) break;
            for (int i = u; i <= d; i++) vec.push_back(matrix[i][r]);
            if (--r < l) break;
            for (int i = r; i >= l; i--) vec.push_back(matrix[d][i]);
            if (--d < u) break;
            for (int i = d; i >= u; i--) vec.push_back(matrix[i][l]);
            if (++l > r) break;  
        }
        return vec;
    }
};