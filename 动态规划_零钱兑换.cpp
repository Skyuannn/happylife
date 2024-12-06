#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> vec(amount + 1, amount + 1);
        vec[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    vec[i] = min(vec[i], vec[i - coins[j]] + 1);
                }
            }
        }
        return vec[amount] > amount ? -1 : vec[amount];
    }
}; 

int main() {
    Solution S;
    int amount;
    int n;
    cout << "请输入数组个数 n " << endl;
    cin >> n;
    vector<int> vec(n);
    cout << "请输入一个整数数组 coins " << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    cout << "请输入一个整数 amount " << endl;
    cin >> amount;
    int result = S.coinChange(vec, amount);
    cout << "最少需要的硬币数量: " << result << endl;
    return 0;
}
