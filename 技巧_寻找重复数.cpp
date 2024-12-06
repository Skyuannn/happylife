#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) break;
        }
        int ptr = 0;
        while (true) {
            ptr = nums[ptr];
            slow = nums[slow];
            if (slow == ptr) break;
        }
        return slow;
    }
};