#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 动态规划法.时间复杂度：O(n2),空间复杂度：O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec(nums.size());
        vec[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    vec[i] = max(vec[i] ,vec[j] + 1);
                }
                else vec[i] = max(vec[i], 1);
            }
        }
        return *max_element(vec.begin(), vec.end());
    }
};

int main() {
    Solution S;
    int n;
    cout << "数组个数" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "输入数组" << endl;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int result = S.lengthOfLIS(nums);
    cout << "长度为:" << result << endl;
    return 0;
}