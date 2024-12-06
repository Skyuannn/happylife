// 递归法.时间复杂度：O(n),空间复杂度：O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        mid(root, vec);
        return vec;
    }

    void mid(TreeNode *root, vector<int> &vec) {
        if (!root) return;
        mid(root->left, vec);
        vec.push_back(root->val);
        mid(root->right, vec);
    }
};

//迭代法.时间复杂度：O(n),空间复杂度：O(n) *
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
