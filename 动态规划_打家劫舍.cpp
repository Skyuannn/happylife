// 时间复杂度：O(n),空间复杂度：O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n + 1);
        vec[0] = 0;
        vec[1] = nums[0];
        for (int i = 2; i < n + 1; i++) {
            vec[i] = max(vec[i - 1], vec[i - 2] + nums[i - 1]);
        }
        return vec[n];
    }
};

// 时间复杂度：O(n),空间复杂度：O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = 0;
        int max_num = 0;
        for (int c : nums) {
            max_num = max(prev + c, curr);
            prev = curr;
            curr = max_num;
        }
        return curr;
    }
};