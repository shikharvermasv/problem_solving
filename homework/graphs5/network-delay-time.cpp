class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> network(n+1 , INT_MAX);

        network[k] =0;
        pq.push({0,k});

        while(!pq.empty()){
            
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjnode = it.first;
                int adjtime = it.second;
                if(time+adjtime < network[adjnode]){
                    network[adjnode] = adjtime+time;
                    pq.push({network[adjnode] , adjnode});
                }
            }
        }
        int ans = -1;
        for(int i=1 ; i<=n ; i++){
            ans = max(network[i] , ans);
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
