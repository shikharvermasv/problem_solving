class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1] , it[2]});// directed graph 
        }
        // priority_queue and the answer vector for storing min cost
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int> ans(n,INT_MAX);

        // initializing source node
        ans[src] = 0;
        pq.push({0,{0,src}});

        while(!pq.empty()){
            int stops = pq.top().first;
            int cost = pq.top().second.first;
            int destination = pq.top().second.second;
            pq.pop();

            // check for the number of stops and exit the loop
            if(stops > k){
                break;
            }

            for(auto it: adj[destination]){
                int adjdestination = it.first;
                int adjcost = it.second;

                // update the cost vector
                if(ans[adjdestination] > cost+adjcost && stops <= k){
                    ans[adjdestination] = cost+adjcost;
                    pq.push({stops+1 , {ans[adjdestination] , adjdestination}});
                }
            }
        }
        if(ans[dst] == INT_MAX){
            ans[dst]=-1;//unreachable node 
        }
        return ans[dst];
    }
};
