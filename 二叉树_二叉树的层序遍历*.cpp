#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> vec;
        queue<TreeNode *> q;
        q.push(root);
        if (!root) return vec;
        while (!q.empty()) {
            vec.push_back(vector<int> ());
            int queueLong = q.size();
            for (int i = 0; i < queueLong; ++i) {
                TreeNode *root = q.front();
                vec.back().push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
                q.pop();
            }
        }
        return vec;
    }
};