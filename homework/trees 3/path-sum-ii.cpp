class Solution {
public:
    vector<vector<int>> ans;
    void pathsum(TreeNode* root , int sum , vector<int> v){
        if(!root){
            return;
        }

        if(!root->left && !root->right){
            if(sum == root->val){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        vector<int> temp = v;
        v.push_back(root->val);
        temp.push_back(root->val);
        pathsum(root->right, sum-(root->val), v);
        pathsum(root->left, sum-(root->val), temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathsum(root , targetSum , {});
        return ans;
    }
};
