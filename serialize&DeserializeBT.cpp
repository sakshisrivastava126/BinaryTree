/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        
        //create a queue and push the root
        queue<TreeNode*> q;
        q.push(root);

        //keep poping and pushing the L & R nodes while adding to the string
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) s.append("#,");
            else{
             s.append(to_string(curr->val)+",");   
            }
            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream ss(data);
        string str;
        getline(ss, str, ','); //getting 1st string/value

        //creating root out of it
        TreeNode* root = new TreeNode(stoi(str));

        //creating queue and pushing the root
        queue<TreeNode*> q;
        q.push(root);
        
        //pop and push the nodes
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            //get string for left
            getline(ss, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                //if not null
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left); //at the end push in the queue
            }

            getline(ss, str, ',');
            //for right
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
