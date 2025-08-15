/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
private:
    void solve(Node* root, vector<int>& ans, int lvl){
        if(!root) return;
        //this line means we have reached a new level and haven't pushed any node from that level
       // so we push the first node that we find in that level ie left most node as we are making recursive call for left first
       //this is for 0 based indexing for levels
        if(lvl == ans.size()) ans.push_back(root->data);
        
        solve(root->left, ans, lvl+1);
        solve(root->right, ans, lvl+1);
    }
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
