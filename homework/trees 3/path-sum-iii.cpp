class Solution {
public:

    int solve(TreeNode* root , int sum ){
        if(root == NULL || sum <  -19999999){
            return 0;
        }
        int count = 0;
        if(root->val == sum){
            count++;
        }

        count += solve(root->left , sum-(root->val));
        count += solve(root->right , sum-(root->val));

        return count;
    }

    int pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return 0;
        }
        return pathSum(root->left , sum) + solve(root , sum) + pathSum(root->right , sum);
    }
};
