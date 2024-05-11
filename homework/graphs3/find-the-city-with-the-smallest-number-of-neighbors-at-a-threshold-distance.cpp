class Solution {
public:
    void floyd(vector<vector<int>>&adj, int n){
        for(int k = 0; k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    adj[i][j] = min(adj[i][j], (adj[i][k]+adj[k][j]));
                }
            }
        }
    }


    int findTheCity(int n, vector<vector<int>>& edges, int T) {
        vector<vector<int>>adj(n,vector<int>(n,1e5));
        for(auto it:edges){
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++) 
            adj[i][i] = 0;
        

        floyd(adj, n);

        int Max = n;
        int No = -1;

        for(int i=0;i<n;i++) {
            int count=0;
            for(int j=0;j<n;j++) {
                if(adj[i][j] <= T) {
                    count++;
                }
            }
            if(count <= Max) {
                Max = count;
                No = i;
            }

        }
        return No;
    }
};
