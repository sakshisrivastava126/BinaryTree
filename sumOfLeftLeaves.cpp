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
private:
    void sumOfLeft(TreeNode* root, int& sum, bool l) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && l == true){
            sum += root->val;
            return;
        }

        if(root->left) {
            sumOfLeft(root->left, sum, true);
        }
        if(root->right){
            sumOfLeft(root->right, sum, false);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root->left == NULL && root->right == NULL){
            return sum;
        }
        sumOfLeft(root, sum, false);
        return sum;
    }
};
