#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isCovered(int sts[], int stt[]) {
        for (int i = 'a'; i <= 'z'; i++) {
            if (sts[i] < stt[i]) return false;
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            if (sts[i] < stt[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length();
        int st_left = -1, st_right = n;
        int sts[128]{};
        int stt[128]{};
        for (char c : t) {
            ++stt[c];
        }
        int left = 0;
        for (int right = 0; right < n; right++) {
            ++sts[s[right]];
            while (isCovered(sts, stt)) {
                if (right - left < st_right - st_left) {
                    st_left = left;
                    st_right = right;
                }
                --sts[s[left]];
                ++left;
            }
        }
        return st_left < 0 ?  "" : s.substr(st_left, st_right - st_left + 1);
    }
};