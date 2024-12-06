#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> vec(n, vector<int>(n));
        for (int i = 0; i < n; i++) vec[i][i] = true;
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n; i++) {
                int j = L + i - 1;
                if (j >= n) break;
                if (s[i] != s[j]) vec[i][j] = false;
                else {
                    if (j - i < 3) vec[i][j] = true;
                    else vec[i][j] = vec[i + 1][j - 1];
                }
                if (vec[i][j] && j - i + 1 > maxLen) {
                    begin = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main() {
    string s{"babad"};
    Solution S;
    string result = S.longestPalindrome(s);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}