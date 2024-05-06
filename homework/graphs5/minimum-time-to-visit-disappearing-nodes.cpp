class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        // adj list for the graph
        for(auto it: edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        vector<int> temp(n , INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        //initializing the priority queue and vector
        temp[0] = 0;
        pq.push({0,0});

        // dijkstra algo
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // because it already vis
            if(temp[node] < w){
                continue;
            }
            for(auto it: adj[node]){
                int adjw = it.second;
                int adjnode = it.first;

                if(w+adjw < temp[adjnode] && w+adjw < disappear[adjnode]){
                    temp[adjnode] = w+adjw;
                    pq.push({temp[adjnode] , adjnode});
                }
            }
        }
        // giving value of -1 to all the disappeared node of the graph where we can not reach
        for(int i=0 ; i<n ; i++){
            if(temp[i] == INT_MAX){
                temp[i] = -1;
            }
        }

        return temp;
    }
};
