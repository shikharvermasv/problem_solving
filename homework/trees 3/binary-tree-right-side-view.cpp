class Solution {
public:
    void rightview(TreeNode* root , int level , vector<int>& ans){
        if(root == NULL){
            return ;
        }
        if( ans.size() <= level){
            ans.push_back(root->val);
        }
        rightview(root->right , level +1 , ans);
        rightview(root->left , level +1 , ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        int level =0 ;
        vector<int> ans;
        rightview(root , level ,ans);
        return ans;
    }
};
