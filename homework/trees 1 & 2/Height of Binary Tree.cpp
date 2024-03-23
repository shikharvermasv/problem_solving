int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(root == NULL){
        return 0;
    }

    int left = heightOfBinaryTree(root->left)+1;
    int right = heightOfBinaryTree(root->right)+1;

    return max(left,right);
}
