class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int s, int e) {
        vector<vector<pair<int,double>>>adj(n);
        // adj list for the graph
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] , succ[i]});
            adj[edges[i][1]].push_back({edges[i][0] , succ[i]});
        }

        vector<double>probability(n,0); // we will not take INT_MIN because we need min of 0 as a ans for no path
        // max heap for maximum probability 
        priority_queue<pair<double,int>> pq;

        probability[s] =1;
        pq.push({1,s});
        // dijkstra algo
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it: adj[node]){
                int adjnode = it.first;
                double adjprob = it.second;

                if(prob*adjprob > probability[adjnode]){
                    probability[adjnode] = prob*adjprob;
                    pq.push({probability[adjnode] , adjnode});
                }
            }

        }
        return probability[e];
    }
};
