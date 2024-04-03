class Solution {
public:
    void inorder(TreeNode* root , vector<int>&vec) {
        if (root == nullptr)
            return;

        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right , vec);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root , vec);

        int n = vec.size();

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = vec[i] + vec[j];
            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else if (sum > k)
                j--;
        }
        return false;
    }
};
