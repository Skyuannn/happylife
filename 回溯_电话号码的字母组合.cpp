#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, string> hash{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
public:
    vector<string> vec;
    string v;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vec;
        dfs(digits, 0);
        return vec;
    }   

    void dfs(string digits, int x) {
        if (x == digits.size()) {
            vec.push_back(v);
            return;
        }
        string letters = hash[digits[x]];
        for (int i = 0; i < letters.size(); i++) {
            v.push_back(letters[i]);
            dfs(digits, x + 1);
            v.pop_back();
        }
    }
};