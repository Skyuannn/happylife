#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j =  1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    //grid 是一个 vector<vector<int>> 类型的对象，sizeof(grid) 的值通常固定为 24 字节
    cout << sizeof(grid) << endl;
    //&grid 是一个指针，指向 grid 对象的地址，在 64 位系统上，指针的大小通常是 8 字节
    cout << sizeof(&grid) << endl; 
    Solution S;
    int result = S.minPathSum(grid);
    cout << "result:" << result << endl;
    return 0;
}