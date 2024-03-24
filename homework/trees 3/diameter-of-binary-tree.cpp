class Solution {
public:
    int diameter(TreeNode* root , int& count){
        if(root == NULL){
            return 0;
        }
        int left = diameter(root->left , count);
        int right = diameter(root->right , count);

        count = max(count , left+right);
        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int count =0;
        diameter(root , count);
        return count;
    }
};
