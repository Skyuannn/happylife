#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> vec;
    vector<string> v;
    int n;
    void dfs(string s, int i) {
        if (i == n) {
            vec.emplace_back(v);
            return;
        }
        for (int j = i; j < n; j ++) {
            if (f[i][j]) {
                v.emplace_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; j++) {
                f[i][j] = (s[i] == s[j] && f[i + 1][j - 1]);
            }
        }
        dfs(s, 0);
        return vec;
    }
};