#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution{
 public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p){
        TreeNode* predecessor = NULL;

        while(root != NULL){
            if(p->val > root->val){
                predecessor = root;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return predecessor;
    }   
 };

 TreeNode* insert(TreeNode* root, int val){
    if(!root) return new TreeNode(val);
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
 }

 TreeNode* findNode(TreeNode* root, int val){
    if(!root || root->val == val) return root;
    if(val < root->val) return findNode(root->left, val);
    else return findNode(root->right, val);
 }

 int main(){
    TreeNode* root = NULL;
    root = insert(root,20);
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 3);
    insert(root, 15);
    insert(root, 40);

    int key = 15;
    TreeNode* target = findNode(root, key);

    Solution sol;
    TreeNode* pred = sol.inorderPredecessor(root, target);

    if(pred) {
        cout << "Inorder predecessor is " << pred->val << endl;
    }
    else{
        cout << "predecessor doesn't exist";
    }
    return 0;
 }
