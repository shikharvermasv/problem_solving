class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int low, int high){
        if(high<low)
        return NULL;
        TreeNode* root = new TreeNode(preorder[low]);
        int i = low+1;
        while(i<=high){
            if(preorder[i]>preorder[low]){
                break;
            }
            i++;
        }
        root->left = solve(preorder,low+1,i-1);
        root->right = solve(preorder,i, high);

        return root;

    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int low = 0;
        int high = preorder.size()-1;
        return solve(preorder,low,high);
        
    }
};
