class Solution {
public:

    void dfs(int node,vector<int>&vis, vector<vector<int>>&adj){
        if(adj[node].size()==0)
            return;
        for(int i=0;i<adj[node].size();i++){
            if(vis[adj[node][i]]==-2){
                vis[adj[node][i]]=node;
                dfs(adj[node][i], vis,adj);
            }else
                vis[adj[node][i]]=node;
        }
        return;
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,-2);
        vector<int>ans;
        vector<vector<int>>adj(n,vector<int>());

        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back(edges[i][1]);

        for(int i=0;i<n;i++){
            if(vis[i]==-2){
                vis[i]=-1;
                dfs(i, vis,adj);
            }
        }

        for(int i=0;i<n;i++)
            if(vis[i]==-1)
                ans.push_back(i);

        return ans;
    }
};
