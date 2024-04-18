class Solution {
public:

// wew will make a visited array and call dfs for it then all the 
//connecting node will get true and we will again call it only for false node 
//the count will increase

    void dfs(vector<vector<int>>& isConnected , int i , vector<bool>& vis){
        vis[i] = true;
        for(int j=0 ; j<isConnected.size() ; j++){
            if(isConnected[i][j] == 1 && vis[j] == false){
                dfs(isConnected , j , vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <bool> vis(isConnected.size(), false);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (vis[i] == false) {
                dfs(isConnected, i, vis);
                count++;
            }
        }
        return count;
    }
};
