#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        vector<int> vec;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        vec = {q.top().first};
        for (int i = k; i < n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) q.pop();
            vec.push_back(q.top().first);
        }
        return vec;
    }
};

int main() {
    int n;
    int k;
    cout << "请输入数组个数:" << endl;
    cin >> n;
    cout << "请输入滑动值K:" << endl;
    cin >> k;
    cout << "请输入数组:" << endl;
    vector<int> nums(n);
    vector<int> vec(n - k);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution S;
    vec = S.maxSlidingWindow(nums, k);
    cout << "最大值:";
    for (int i = 0; i < n - k; i++) {
        cout << vec[i];
    }
    cout << endl;
    return 0;
}