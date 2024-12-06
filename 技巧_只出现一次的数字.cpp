// 位运算:位与（&）、位或（|）、位异或（^）
// 任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a
// 任何数和其自身做异或运算，结果是 0，即 a⊕a=0
// 异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int &num :nums) ret ^= num;
        return ret;
    }
};