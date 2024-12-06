#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;
        int a_max, b_min;
        while (l <= r) {
            int i = (r + l) / 2;
            int j = (m + n + 1) / 2 - i;
            int ai = (i == 0 ? INT_MIN : nums1[i - 1]);
            int bi = (i == m ? INT_MAX : nums1[i]);
            int aj = (j == 0 ? INT_MIN : nums2[j - 1]);
            int bj = (j == n ? INT_MAX : nums2[j]);
            if (ai < bj) {
                a_max = max(ai, aj);
                b_min = min(bi, bj);
                l = i + 1;
            }   
            else r = i - 1;
        }
        return (m + n) % 2 == 0 ? (a_max + b_min) / 2.0 : a_max; 
    }
};

int main() {
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    Solution S;
    double result = S.findMedianSortedArrays(nums1, nums2);
    cout << "result:" << result << endl;
    return 0;
}