/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root == NULL) return NULL;
      int curr = root->val;
      if(p->val < curr && q->val < curr){ //if both are smaller move left
        return lowestCommonAncestor(root->left, p, q);
      }  
      if(p->val > curr && q->val > curr){ //if both are larger move right
        return lowestCommonAncestor(root->right, p, q);
      }  
      return root;   //if none of above happens then it means we cant decide whether to go left or right so we return that node and that node is our LCA
    }
};
