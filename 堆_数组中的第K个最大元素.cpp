#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return check(nums, 0, n - 1, n - k);
    }

    int check(vector<int> &nums, int l, int r, int k) {
        if (l == r) return nums[k];
        int i = l - 1, j = r + 1;
        while (i < j)
        {
            int num = nums[l];
            do i++; while (nums[i] < num);
            do j--; while (nums[j] > num);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (j < k) return check(nums, j + 1, r, k);
        else return check(nums, l, j, k);
    }
};

int main() {
    vector<int> nums{3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution S;
    int result = S.findKthLargest(nums, k);
    cout << "result:" << result << endl;
    return 0;
}