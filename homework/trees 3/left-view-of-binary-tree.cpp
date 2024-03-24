void leftview(BinaryTreeNode<int>* root , int level , vector<int> & ans){
    if(root == NULL){
        return ;
    }
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    leftview(root->left , level+1 , ans);
    leftview(root->right , level+1 , ans);
}


vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    int level =0;
    vector<int>ans;

    leftview(root , level , ans);

    return ans;

}
