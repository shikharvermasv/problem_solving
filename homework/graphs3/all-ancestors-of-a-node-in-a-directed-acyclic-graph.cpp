class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>&adj , vector<vector<int>>&ans , vector<bool>&vis){
        vis[j] = true;
        for(auto &it : adj[j]){
            if(!vis[it]){
                ans[it].push_back(i);
                dfs(i , it , adj , ans , vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n);
        vector<vector<int>> adj(n);

        for(int i=0 ; i<edges.size() ; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0 ;i<n ;i++){
            vector<bool>vis(n);
            dfs(i , i , adj , ans , vis);
        }
        return ans;
    }
};
