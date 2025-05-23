class Solution {
public:
    int findCeil(Node* root, int input) {
        if (root == NULL)
            return -1;

        int ceil = -1;
        while (root) {
            if (input == root->data) {
                return root->data;
            }
            if (input > root->data) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};
