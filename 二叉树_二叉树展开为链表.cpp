class Solution {
    vector<int> vec;
public:
    void flatten(TreeNode* root) {
        check(root, vec);
        int n = vec.size();
        TreeNode *node = root;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                node->val = vec[i];
                break;
            }
            node->val = vec[i];
            node->right = new TreeNode();
            node->left = nullptr;
            node = node->right;
        }
    }

    void check(TreeNode *root, vector<int> &vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        check(root->left, vec);
        check(root->right, vec);
    }
};