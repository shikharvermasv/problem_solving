class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(!root){
            return ans;
        }
        
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            Node* temp=q.front().first;
            int horidis=q.front().second;
            q.pop();
            
            m[horidis]=temp->data;
            
            if(temp->left){
                q.push({temp->left,horidis-1});
            }
            if(temp->right){
                q.push({temp->right,horidis+1});
            }
        }
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
