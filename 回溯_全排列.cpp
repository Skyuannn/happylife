#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> vec;
    void dfs(vector<int> &nums, int x) {
        if (x == nums.size() - 1) {
            vec.emplace_back(nums);
            return;
        }
        for (int i = x; i < nums.size(); i++) {
            swap(nums[i], nums[x]);
            dfs(nums, x + 1);
            swap(nums[i], nums[x]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return vec;
    }
};