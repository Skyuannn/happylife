#include <vector>
using namespace std;

// 时间复杂度:O(Log(M)+Log(N)),空间复杂度:O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, l = 0, r = n - 1;
        
        while (i < m && matrix[i][n - 1] < target) {
            i++;
        }
        if (m == i) return false;
        while (r >= l) {
            int mid = (l + r) / 2;
            if (matrix[i][mid] == target) return true;
            if (matrix[i][mid] > target) {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return false;
    }
};