// 双指针法,时间复杂度：O(n),空间复杂度：O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};

// 动态规划法,时间复杂度：O(n),空间复杂度：O(n)
class Solution{
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        int ans = 0;
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >=0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};