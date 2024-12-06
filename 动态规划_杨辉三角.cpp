#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vec(numRows);
        if (numRows == 0) return vec;
        for (int i = 0; i < numRows; i++) {
            vec[i].resize(i + 1);
            vec[i][0] = vec[i][i] = 1;
            for (int j = 1; j < i; j++) {
                vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
            }
        }
        return vec;
    }
};

int main() {
    Solution S;
    int numRows;
    cout << "请输入 numRows 行" << endl;
    cin >> numRows;
    vector<vector<int> > vec = S.generate(numRows);
    for (const auto &row : vec) {
        for (int val : row) {
            cout << val << " ";  // 输出每一行的元素
        }
        cout << endl;  // 每行输出后换行
    }
    return 0;
}