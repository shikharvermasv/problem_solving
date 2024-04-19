class Solution {
  public:
  // make a visited array and marks the node visited or not , then traverse it using dfs and if the node reaches the visited
  // node the it is cyclic otherwise no
  
    bool dfs(int i, vector<int>&vis,vector<int> adj[]){
        vis[i] = 2;
        
        for(auto it: adj[i]){
            if(vis[it]==2){
                return true;
            }
            else if(!vis[it]){
                if(dfs(it,vis,adj)){
                    return true;
                }
            }
        }
        vis[i]=1;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int>vis(n,0);
        for(int i=0 ; i<n ; i++){
            if(!vis[i] && dfs(i, vis , adj)){
                return true;
            }
        }
        return false;
    }
};
