class Solution {
public:
    void bst(TreeNode* root , vector<int>& ans){
        if(root == NULL){
            return ;
        }
        bst(root->left , ans);
        ans.push_back(root->val);
        bst(root->right , ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        bst(root , ans);
        for(int i=1 ; i<ans.size() ; i++){
            if(ans[i-1] >= ans[i]){
                return false;
            }
        }
        return true;
    }
};
