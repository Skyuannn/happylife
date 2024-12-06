class Solution {
    unordered_map<int, int> hash;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        return check(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *check(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (in_left > in_right) return nullptr;
        int pre_root = preorder[pre_left];
        int in_root = hash[preorder[pre_left]];
        int left_num = in_root - in_left;
        TreeNode *root = new TreeNode(pre_root);
        root->left = check(preorder, inorder, pre_left + 1, pre_left + left_num, in_left, in_root - 1);
        root->right = check(preorder, inorder, pre_left + left_num + 1, pre_right, in_root + 1, in_right);
        return root;
    }
};