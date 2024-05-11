class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);

        for(int i = 0;i<points.size();i++){
            auto p1 = points[i];
            int x1 = p1[0];
            int y1 = p1[1];
            for(int j = i+1;j<points.size();j++){
                auto p2 = points[j];
                int x2 = p2[0];
                int y2 = p2[1];

                int dis = abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});

            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        int ans = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();

            int wt = f.first;;
            int node = f.second;

            if(vis[node]) continue;

            vis[node] = 1;
            ans += wt;

            for(auto i: adj[node]){
                int adjwt = i.second;
                int adjnode = i.first;
                
                if(!vis[adjnode])
                pq.push({adjwt, adjnode});
            }
        }
        return ans;
    }
};
