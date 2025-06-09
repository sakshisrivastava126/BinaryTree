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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL){
            //case1: when left is null
            if(curr ->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            //when left isn't null
            else{
                //irterate to rightmost node of the left subtree
                TreeNode *prev = curr->left;
                //checking right exist or not AND checking incase we are returning and thread already exist
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                //if we have reached null then create the thread
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    //threaded node already exist, we are removing the thread here
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
