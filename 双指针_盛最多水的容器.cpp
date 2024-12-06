// 双指针法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size() - 1;
        int i = 0;
        int area = 0;
        while (i < j) {
            int ans = min(height[i], height[j]) * (j - i);
            area = max(ans, area);
            if (height[i] > height[j]) --j;
            else ++i;
        }
        return area;
    }
};