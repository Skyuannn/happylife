class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        for (int i = 0; i < intervals.size(); i++) {
            int First = intervals[i][0];
            int Second = intervals[i][1];
            if (vec.size() && vec.back()[1] >= First) {
                vec.back()[1] = max(vec.back()[1], Second);
            }
            else {
                vec.push_back({First, Second});
            }
        }
        return vec;
    }
};