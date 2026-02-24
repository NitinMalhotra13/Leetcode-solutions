class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        curr = curr * 2 + node->val;

        // If leaf node
        if (!node->left && !node->right)
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }
};
