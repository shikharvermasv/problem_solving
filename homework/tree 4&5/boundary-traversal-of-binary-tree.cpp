// first left dekhenge
// left me leaf add nahi karna hai
// then leaf dekhenge
// then right

bool isLeaf(TreeNode<int> * node){

    if(node->left==NULL && node->right==NULL) return true;

    return false;

}

void left(TreeNode<int> * root , vector<int>& ans){
    TreeNode<int>* temp = root->left;
    while(temp){
        if(!isLeaf(temp) ){
            ans.push_back(temp->data);
        }
        if(temp->left){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
}

void leaf(TreeNode<int> * root , vector<int> & ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left){
        leaf(root->left ,ans);
    }
    if(root->right){
        leaf(root->right ,ans);
    }
}

void right(TreeNode<int> * root , vector<int>& ans){
    TreeNode<int> * temp = root->right;
    vector<int> a;
    while(temp){
        if(!isLeaf(temp)){
            a.push_back(temp->data);
        }
        if(temp->right){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }

    for(int i=a.size()-1 ; i>=0 ; i--){
        ans.push_back(a[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ans;
    if(!root){
        return ans;
    }
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
    left(root,ans);
    leaf(root,ans);
    right(root,ans);

    return ans;
}
