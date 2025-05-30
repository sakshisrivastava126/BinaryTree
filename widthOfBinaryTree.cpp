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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        //creating a queue to store the pair of node and index
        queue<pair<TreeNode*, unsigned long long>> q;
        //root of the tree push kra sabse pehle
        q.push({root,0});

        while(!q.empty()){
            int first, last;
            unsigned long long size = q.size();
            unsigned long long mmin = q.front().second;

            for(int i=0; i<size; i++){
                //curr is current index
                unsigned long long curr = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                //setting the value of first and last nodes
                if(i==0) first = curr;
                if(i==size-1) last = curr;
                //giving index to left and right nodes
                if(node->left){
                    q.push({node->left, curr*2 +1});
                }
                if(node->right){
                    q.push({node->right, curr*2 +2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
