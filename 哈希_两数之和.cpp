// 暴力法
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                } 
            }
        }
        return {};
    }
};

// 哈希法 
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int taget){
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i){
            auto it = hashtable.find(taget - nums[i]);
            if (it != hashtable.end()){
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};