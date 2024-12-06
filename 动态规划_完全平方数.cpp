#include<vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> vec(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, vec[i - j * j]);
            }
            vec[i] = minn + 1;
        }
        return vec[n];
    }
};

int main() {
    Solution S;       
    int n;
    cout << "请输入一个整数" << endl;
    cin >> n;
    int result = S.numSquares(n);
    cout << "结果是：" << result << endl;
    return 0;
}