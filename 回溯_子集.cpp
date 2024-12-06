#include <vector>
using namespace std;

// 回溯法
class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return vec;
    }
    void dfs(vector<int> nums, int x) {
        if (x == nums.size()) {
            vec.emplace_back(v);
            return;
        }
        v.emplace_back(nums[x]);
        dfs(nums, x + 1);
        v.pop_back();
        dfs(nums, x + 1);
    }
};

// 列表迭代法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec{{}};
        for (const auto &num : nums) {
            for (int i = vec.size() - 1; i >= 0; i--) {
                vector<int> v = vec[i];
                v.emplace_back(num);
                vec.emplace_back(v);
            }
        }
        return vec;
    }
};