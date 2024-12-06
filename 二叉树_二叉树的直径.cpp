class Solution {
    int long_max;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        long_max = 0;
        check(root);
        return long_max;
    }

    int check(TreeNode *root) {
        if (root == nullptr) return -1;
        int left = check(root->left) + 1;
        int right = check(root->right) + 1;
        long_max = max(long_max, left + right);
        return max(left, right);
    }
};