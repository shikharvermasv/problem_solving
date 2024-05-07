class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        int ans=INT_MAX;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        
        for(int i=0;i<n;i++){
            vector<int> vis(n,INT_MAX);
            vector<int> prev(n, -1);

            vis[i]=0;
            q.push(i);
            while(!q.empty()){
                int src=q.front();
                q.pop();

                for(auto it:adj[src]){
                    if(vis[it]==INT_MAX){
                        vis[it]=vis[src]+1;
                        prev[it]=src;
                        q.push(it);
                    }
                    else{
                        if(prev[src]==it || prev[it]==src) continue;
                        ans=min(ans, abs(vis[src]+vis[it])+1);
                    }
                }
            }
            
            
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
