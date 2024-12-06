#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> hash;
        int right = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) hash.erase(s[i - 1]);
            while (right + 1 < n && !hash.count(s[right + 1])) {
                hash.insert(s[right + 1]);
                ++right;
            }
            ans = max(ans, right - i + 1);
        }
        return ans;
    }
};