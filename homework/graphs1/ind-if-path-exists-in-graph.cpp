class Solution {
public:
    bool dfs(vector<vector<int>>& adj , vector<int>&vis , int s , int d){
        if(s==d){
            return true;
        }
        if(!vis[s]){
           vis[s] =1;
            for(int i=0 ; i<adj[s].size() ; i++){
                if(dfs(adj , vis , adj[s][i], d)){
                    return true;
                }
            }   
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj , vis , source , destination);
    }
};
