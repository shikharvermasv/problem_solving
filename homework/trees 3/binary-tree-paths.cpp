class Solution {
public:
    void path(TreeNode* root , string s , vector<string>& ans){
        if(!root){
            return ;
        }
        s+=to_string (root->val);
        if(!root->left && !root->right){
            ans.push_back(s);
        }
        else{
            path(root->left , s+ "->" , ans);
            path(root->right , s+ "->" , ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        path(root , s , ans);
        return ans;
    }
};
