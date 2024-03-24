class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = invertTree(right);
        root->right = invertTree(left);
        
        return root;
    }
};
