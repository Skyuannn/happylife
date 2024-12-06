class Solution {
    vector<int> num;
public:
    bool isValidBST(TreeNode* root) {
        check(root, num);
        int n = num.size();
        for (int i = 1; i < n; i++) {
            if (num[i] <= num[i - 1]) return false;
        }
        return true;
    }

    void check(TreeNode *root, vector<int> &num) {
        stack<TreeNode *> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            num.push_back(root->val);
            root = root->right;
        }
    }
};