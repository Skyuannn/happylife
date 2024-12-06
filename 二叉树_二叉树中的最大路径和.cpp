class Solution {
    int ans = 0;
public:
    int maxPathSum(TreeNode* root) {
        check(root);
        return ans;
    }

    int check(TreeNode *root) {
        if (root == nullptr) return 0;
        int L = check(root->left);
        int R = check(root->right);
        ans = max(ans, L + R + root->val);
        return max(L, R) + root->val;
    }
};