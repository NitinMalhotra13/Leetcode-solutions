class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        maxPathDown(root, maxValue);
        return maxValue;
    }

    int maxPathDown(TreeNode* node, int &maxValue) {
        if (!node) return 0;

        int left = max(0, maxPathDown(node->left, maxValue));
        int right = max(0, maxPathDown(node->right, maxValue));

        maxValue = max(maxValue, left + right + node->val);

        return max(left, right) + node->val;
    }
};
