class Solution {
public:
    bool paths(TreeNode* root, int targetSum , int sum){
        if(root == NULL){
            return false;
        }
        else if(root->left == NULL && root->right==NULL){
            sum = sum+ root->val;
            if(sum == targetSum){
                return true;
            }
        }
        return paths(root->left , targetSum , sum + root->val) || paths(root->right , targetSum , sum+ root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        return paths(root , targetSum , sum);
    }
};
