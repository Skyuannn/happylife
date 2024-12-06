#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size() - 1);
    }

    int find(vector<int> &nums, int target, int l, int r) {
        while (r >= l) {
            int n = (r + l) / 2;
            if (nums[n] >= target) r--;
            else l++;
            
        }
        return l;
    } 
};
