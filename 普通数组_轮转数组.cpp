#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return nums;
    }
};

int main() {
    Solution S;
    int n;
    cout << "请输入数组个数：" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "请输入数组：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cout << "请输入轮转个数：" << endl;
    cin >> k;
    vector<int> result = S.rotate(nums, k);
    cout << "输出：";
    for (int i = 0; i < n; i++) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}