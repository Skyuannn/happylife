#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (auto &num : nums) {
            hash[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto &[a, b] : hash) {
            if (q.size() == k) {
                if (b > q.top().second) {
                    q.pop();
                    q.emplace(a, b);
                }
            }
            else q.emplace(a, b);
        }
        vector<int> vec;
        while (!q.empty()) {
            vec.emplace_back(q.top().first);
            q.pop();
        }
        return vec;
    }
};

int main() {
    vector<int> vec;
    vector<int> nums{6, 1, 1, 2, 2, 2, 3, 7, 7, 7, 7, 7, 6, 6, 6};
    int k = 3;
    Solution S;
    vec = S.topKFrequent(nums, k);
    cout << "result:" << endl;
    for (auto &v : vec) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}