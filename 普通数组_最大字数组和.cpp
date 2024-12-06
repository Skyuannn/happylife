#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int pre = 0;
        int max_sum = nums[0];
        for (const auto &c : nums) {
            pre = max(c, pre + c);
            max_sum = max(max_sum, pre);
        }
        return max_sum;
    }
};

int main() {
    Solution S;
    cout << "请输入数组个数：" << endl;
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "请输入数组：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = S.maxSubArray(nums);
    cout << "最大和为：" << result << endl;
    return 0;
}