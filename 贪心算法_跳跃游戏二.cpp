#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_step = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (max_step >= i) {
                max_step = max(max_step, i + nums[i]);
                if (i == end) {
                    end = max_step;
                    step++;
                }
            }
        }
        return step;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 1, 4};
    Solution S;
    int result = S.jump(nums);
    cout << "result:" << result << endl;
    return 0;
}