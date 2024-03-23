class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* leftmost;
        while(!q.empty()){
            leftmost = q.front();
            q.pop();
            if(leftmost->right){
                q.push(leftmost->right);
            }
            if(leftmost-> left){
                q.push(leftmost->left);
            }
        }
        return leftmost->val;
    }
};
