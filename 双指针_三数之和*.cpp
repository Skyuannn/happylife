class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int third = n - 1;
            for (int second = first + 1; second < n; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                while (second < third && nums[first] + nums[second] + nums[third] > 0) {
                    third--;
                }
                if (second == third) break;
                if (nums[first] + nums[second] + nums[third] == 0) vec.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return vec;
    }
};