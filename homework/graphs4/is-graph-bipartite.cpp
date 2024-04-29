class Solution {
public: 
    bool dfs(int i , vector<int>& color , vector<vector<int>>& graph , int col){
        color[i] = col;
        for(auto& j : graph[i]){
            if(color[j] == col){
                return false;
            }
            else if(color[j] == -1){
                if(dfs( j , color , graph , !col) == false){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n , -1);

        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                if(dfs(i , color , graph , 0) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
