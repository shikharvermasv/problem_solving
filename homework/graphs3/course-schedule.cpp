class Solution {
public:
    bool cycle(vector<vector<int>>&adj , int i , vector<int>&vis){
        if(vis[i] == 1){
            return true;
        }
        if(vis[i] == 0){
            vis[i] = 1;
            for(auto j: adj[i]){
                if(cycle(adj , j , vis)){
                    return true;
                }
            }
        }
        vis[i] = -1;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0 ;i<pre.size() ; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }   
        vector<int> vis(n,0);
        for(int i=0 ; i<n ; i++){
            if(cycle(adj , i , vis)){
                return false;
            }
        }
        return true; 
    }
};
