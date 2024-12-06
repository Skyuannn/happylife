#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int maxEle = 0;
        int out;
        for (int &num : nums) {
            hash[num]++;
            if (hash[num] > maxEle) {
                maxEle = hash[num];
                out = num;
            }
        }
        return out;
    }
};