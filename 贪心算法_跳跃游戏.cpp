#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int> &nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums{3, 2, 1, 0, 4};
    Solution S;
    bool result = S.canJump(nums);
    cout << "result:" << result << endl;
    return 0;
}