#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        auto hash = unordered_set<string> ();
        for (string c : wordDict) {
            hash.insert(c);
        }
        auto vec = vector<bool> (s.size() + 1);
        vec[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (vec[j] && hash.find(s.substr(j, i - j)) != NULL) {
                    vec[i] = true;
                    break;
                }
            }
        } 
        return vec[s.size()];
    }
};
