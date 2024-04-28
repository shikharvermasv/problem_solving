class Solution {
public:
    bool cycle(vector<int>& vis , vector<int>& vis1 , vector<vector<int>>& adj , int i){
        vis[i] = 1;
        vis1[i] = 1;

        for(auto j : adj[i]){
            if(!vis[j]){
                if(cycle(vis , vis1 , adj , j)){
                    return true;
                }
            }
            else if(vis1[j]){
                return true;
            }
        }
        vis1[i] = 0;
        return false;
    }

    void orders(vector<int>& vis2 , vector<int>& ans , int i , vector<vector<int>>& adj){
        vis2[i] = 1;
        for(auto j: adj[i]){
            if(!vis2[j]){
                orders(vis2 , ans, j , adj);
            }
        }
        ans.push_back(i);
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> vis1(n,0);
        vector<int> vis2(n,0);

        // adj list;
        vector<vector<int>> adj(n , vector<int>());
        for(int i=0 ; i<pre.size() ; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        // check if the graph have cycle or not 
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                if(cycle(vis , vis1 , adj , i)){
                    return ans;
                }
            }
        }

        // now storing the course in order in the ans vector
        for(int i=0 ;i<n ; i++){
            if(!vis2[i]){
                orders(vis2 , ans , i , adj);
            }
        }
        return ans;
    }
};
