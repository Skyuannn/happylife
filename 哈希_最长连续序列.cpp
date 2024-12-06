class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> nums_set;
        for (const int &num : nums){
            nums_set.insert(num);
        }
        int longgestStreak = 0;
        for (const int &num : nums_set){
            if (!nums_set.count(num - 1)){
                int current_num = num;
                int currentStreak = 1;

                while (nums_set.count(current_num + 1)){
                    current_num += 1;
                    currentStreak += 1;
                }
                longgestStreak = max(longgestStreak, currentStreak);
            }
        }
        return longgestStreak;
    }
};