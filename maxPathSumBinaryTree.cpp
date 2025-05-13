/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;

    int maxPath(TreeNode* node) {
        if (!node) return 0;

        int leftSum = max(maxPath(node->left), 0);
        int rightSum = max(maxPath(node->right), 0);

        int currentPathSum = node->val + leftSum + rightSum;

        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
};
