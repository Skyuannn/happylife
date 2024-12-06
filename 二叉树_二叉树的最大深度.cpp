// 递归法.时间复杂度：O(n),空间复杂度：O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int L = maxDepth(root->left) + 1;
        int R = maxDepth(root->right) + 1;
        return max(L, R);
    }

};