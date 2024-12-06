#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> sortColors(vector<int> &nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        return nums;
    }
};

int main() {
    vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution S;
    vector<int> result = S.sortColors(nums);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ',';
    }
    cout << ']';
    cout << endl;
    return 0;
}