class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        // min heap {diff{row,col}}
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        // diff matrix to store the diff of the cell
        vector<vector<int>> diff(r,vector<int>(c,INT_MAX));
        // initializing the pq and diff matrix
        diff[0][0] = 0;
        pq.push({0,{0,0}});

        // direction array to traverse the mat
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // dijkstra algo 
        while(!pq.empty()){
            int dif = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            //base condition
            if(row == r-1 && col == c-1){
                return dif;
            }

            for(int i=0 ; i<4 ; i++){
                int adjrow = row+dr[i];
                int adjcol = col+dc[i];

                // check for the boundary
                if(adjrow >= 0 && adjcol >= 0 && adjrow < r && adjcol < c){
                    int maxi = max(abs(heights[row][col] - heights[adjrow][adjcol]), dif);

                    if(maxi < diff[adjrow][adjcol]){
                        diff[adjrow][adjcol] = maxi;
                        pq.push({maxi,{adjrow,adjcol}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
};
