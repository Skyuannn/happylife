#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<int> scount(26);
        vector<int> pcount(26);
        vector<int> ans;
        if (slen < plen) return vector<int>();
        for (int i = 0; i < plen; i++) {
            ++scount[s[i] - 'a'];
            ++pcount[p[i] - 'a'];
        }
        if (scount == pcount) ans.emplace_back(0);
        for (int i = 0; i < slen - plen; i++) {
            --scount[s[i] - 'a'];
            ++scount[s[i + plen] - 'a'];
            if (scount == pcount) ans.emplace_back(i + 1);
        }
        return ans;
    }
};