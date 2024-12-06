#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> v;
    string s;
    vector<string> generateParenthesis(int n) {
        dfs(n, n, n);
        return v;
    }

    void dfs(int n, int l, int r) {
        if (l == 0 && r == 0) {
            v.push_back(s);
            return;
        }
        if (l == r) {
            s.push_back('(');
            dfs(n, l - 1, r);
            s.pop_back();
        }
        if (l < r) {
            if (l > 0) {
                s.push_back('(');
                dfs(n, l - 1, r);
                s.pop_back();
            }
            s.push_back(')');
            dfs(n, l, r - 1);
            s.pop_back();
        }
    }
};