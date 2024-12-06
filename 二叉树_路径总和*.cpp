class Solution {
    unordered_map<long long, int> hash;
    long long sum = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        hash[0] = 1;
        return check(root, sum, targetSum);
    }

    int check(TreeNode *root, long long sum, int targetSum) {
        if (root == nullptr) return 0;
        int vec = 0;
        sum += root->val;
        if (hash.count(sum - targetSum)) vec = hash[sum - targetSum];
        hash[sum]++;
        vec += check(root->left, sum, targetSum);
        vec += check(root->right, sum, targetSum);
        hash[sum]--;
        return vec;
    }
};