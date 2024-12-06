#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> vec;
    vector<int> v;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return vec;
    }

    void dfs(vector<int> &candidates, int target, int x, int j) {
        if (x == target) {
            vec.emplace_back(v);
            return;
        }
        if (x > target) return;

        for (int i = j; i < candidates.size(); i++) {
            v.emplace_back(candidates[i]);
            dfs(candidates, target, x + candidates[i], i);
            v.pop_back();
        }
    }
};