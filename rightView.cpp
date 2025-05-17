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
    void helper(TreeNode* root, int lvl, vector<int> &res){
        if(root==NULL) return;
        if(res.size() == lvl) res.push_back(root->val);
        helper(root->right, lvl+1, res);
        helper(root->left, lvl+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, 0 , res);
        return res;
    }
};
