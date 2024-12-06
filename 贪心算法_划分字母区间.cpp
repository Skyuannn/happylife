#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string &s) {
        int dir[26];
        int n = s.size();
        for (int i = 0; i < n; i++) {
            dir[s[i] - 'a'] = i;
        }
        vector<int> vec;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, dir[s[i] - 'a']);
            if (i == end) {
                vec.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return vec;
    }
};

int main() {
    vector<int> vec;
    string s{"ababcbacadefegdehijhklij"};
    Solution S;
    vec = S.partitionLabels(s);
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ',';
    }
    cout << ']' << endl;
    return 0;
}