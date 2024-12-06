#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> vec(n + 1);
        vec[0] = 0;
        for (int i = 1; i <= n; i++) {
            vec[i] = vec[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> hash;
        int ans = 0;
        for (int v : vec) {
            ans += hash.contains(v - k) ? hash[v - k] : 0;
            hash[v]++;
        }
        return ans;
    }
};
