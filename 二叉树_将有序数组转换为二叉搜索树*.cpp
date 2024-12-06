class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return check(nums, 0, nums.size() - 1);
    }

    TreeNode *check(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (right + left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = check(nums, left, mid - 1);
        root->right = check(nums, mid + 1, right);
        return root;
    }
};