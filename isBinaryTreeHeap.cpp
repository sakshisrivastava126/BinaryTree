// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  //count total nodes in the tree
    int countNode(Node* root){
        if(root == NULL) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
    
    //checks whether it is complete binary tree or not
    bool isCBT(Node* root, int i, int size){
        if(root == NULL) return true;
        //if our indexing exceeds the total num of nodes then it is not a CBT
        //even if it gets equals to then it's not CBT coz of 0 based indexing
        if(i>=size) return false;
        else{
            //0 based indexing
            bool left = isCBT(root->left, 2*i + 1, size);
            bool right = isCBT(root->right, 2*i + 2, size);
            return left && right;
        }
    }
    
    bool isMaxHeap(Node* root){
        //if is a leaf node
       if(!root->left && !root->right)
           return true;
       
       //if only left child exists
       if(root->left && !root->right) 
       return (root->data >= root->left->data) && isMaxHeap(root->left);
       
       //if both child exists
       if(root->left && root->right){
           bool check = (root->data >= root->left->data) && (root->data >= root->right->data);
           return check && isMaxHeap(root->left) && isMaxHeap(root->right);
       }
       return false;
    }
    
    bool isHeap(Node* tree) {
        int size = countNode(tree);
        return isCBT(tree, 0, size) && isMaxHeap(tree);
    }
};
