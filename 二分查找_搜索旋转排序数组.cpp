#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = findMin(nums);
        if (target > nums.back()) {
            return bound(nums, 0, i, target);
        }
        return bound(nums, i, nums.size() - 1, target);
    }

private:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums.back()) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }

    int bound(vector<int> &nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};