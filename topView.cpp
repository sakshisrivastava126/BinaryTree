/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<pair<int,Node*>> q; //vertical line, node
        map<int, Node*> mp;
        
        q.push({0, root});
        
        while(!q.empty()){
            Node* currNode = q.front().second;
            int k = q.front().first;
            q.pop();
            
            if(mp.find(k) == mp.end()){
                mp[k] = currNode;
            }
            
            if(currNode->left){
                q.push({k-1, currNode->left});
            }
            if(currNode->right){
                q.push({k+1, currNode->right});
            }
            
        }
        for(auto n : mp){
            ans.push_back(n.second->data);
        }
        return ans;
    }
};
