class Solution {
public:

    vector<int> v{};
    void inorder(TreeNode* root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    void check(TreeNode* root)
    {
        if(root != NULL)
        {
            check(root->left);
            if(root->val != v.back())
            {
                root->val = v.back();
            }
            v.pop_back();
            check(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
       inorder(root);
       sort(v.begin(), v.end(), [](int &a, int &b){return a > b;});
       check(root);

    }
};
