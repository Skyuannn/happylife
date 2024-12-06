#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<int> col(n), on_path(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
        auto dfs = [&](auto &&dfs, int i) {
            if (i == n) {
                vector<string> v(n);
                for (int i = 0; i < n; i++) {
                    v[i] = string(col[i], '.') + 'Q' + string(n -col[i] - 1, '.');
                }
                vec.emplace_back(v);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!on_path[j] && !diag1[i + j] && !diag2[i - j + n - 1]) {
                    col[i] = j;
                    on_path[j] = diag1[i + j] = diag2[i - j + n - 1] = true;
                    dfs(dfs, i + 1);
                    on_path[j] = diag1[i + j] = diag2[i - j + n - 1] = false;
                }
            }
        };
        dfs(dfs, 0);
        return vec;
    }
};

int main() {
    int n;
    cout << "请输入一个整数n:" << endl;
    cin >> n;
    Solution S;
    vector<vector<string>> result;
    result = S.solveNQueens(n);
    cout << "输出:" << endl; 
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}