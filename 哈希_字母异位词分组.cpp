// 排序
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        unordered_map<string, vector<string>> hashtable;
        for (auto &str : strs){
            string key = str;
            sort(key.begin(), key.end());
            hashtable[key].emplace_back(str);
        }

        vector<vector<string>> pd;
        for (auto it = hashtable.begin(); it != hashtable.end(); ++it){
            pd.emplace_back(it->second);
        }
        return pd;
    }
};