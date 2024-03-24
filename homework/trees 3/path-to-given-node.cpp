bool path(TreeNode* root , int key , vector<int>& ans){
    if(root == NULL){
        return false;
    }
    if(root->val == key || path(root->left , key , ans) || path(root->right , key , ans )){
        ans.push_back(root->val);
        return true;
    }
    return false;
}
void reverse(vector<int>& ans){
    int  low=0;
    int high= ans.size();
    while(low < high){
        swap(ans[low] , ans[high-1]);
        low++;
        high--;
    }
}
vector<int> Solution::solve(TreeNode* root, int b) {
    vector<int> ans;
    path(root , b , ans);
    reverse(ans);
    return ans;
}
