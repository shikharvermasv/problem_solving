class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue<pair<Node *, int>>q;
        q.push({root, 0});
        map<int, int>mp;
        vector<int> ans;
        
        while(!q.empty()){
            pair<Node *, int> it = q.front();
            q.pop();
            Node *curr = it.first;
            int h = it.second;
            if(mp[h] == 0){
                mp[h] = curr->data;
            }
            if(curr->left)q.push({curr->left, h-1});
            if(curr->right)q.push({curr->right, h+1});
        }
        
        for(auto i = mp.begin();i!=mp.end();++i){
            ans.push_back(i->second);
        }
        
        return ans;
    }

};
