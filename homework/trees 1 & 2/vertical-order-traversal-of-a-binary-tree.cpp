class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans, traversal;
        if(root==nullptr) {
            return ans;
        }
        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});
        while(!que.empty()) {
            auto cur=que.front();
            que.pop();

            TreeNode *temp=cur.first;
            int x=cur.second.first, y=cur.second.second;

            traversal.push_back({x, y, temp->val});
            if(temp->left!=nullptr) {
                que.push({temp->left, {x-1, y+1}});
            }
            if(temp->right!=nullptr) {
                que.push({temp->right, {x+1, y+1}});
            }
        }
        sort(traversal.begin(), traversal.end());
        vector<int> v={traversal[0][2]};
        for(int i=1;i<traversal.size();i++) {
            if(traversal[i][0]==traversal[i-1][0]) {
                v.push_back(traversal[i][2]);
            } else {
                ans.push_back(v);
                v={traversal[i][2]};
            }
        }
        ans.push_back(v);
        return ans;
    }
};
