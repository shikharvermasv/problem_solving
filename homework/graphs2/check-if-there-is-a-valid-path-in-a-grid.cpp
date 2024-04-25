class Solution {
public:
    // teraversing all directions

    vector<int> x{1,-1,0,0};
    vector<int> y{0,0,1,-1};
    // checking the boundary bounded
    bool valid(int x,int y,int m,int n){
        if(x>=0 && x<m && y>=0 && y<n)
            return true;
        return false;
    }


    bool dfs(vector<vector<int>>& grid , int i , int j , int m , int n , vector<vector<int>>& vis , unordered_map<int,vector<vector<int>>>& mp){
        // reaches the destination return true
        if(i == m-1 && j == n-1){
            return true;
        }
        // marke visited
        vis[i][j] = 1;
        for(int k=0 ; k<4 ; k++){
            if(valid(i+x[k] , j+y[k] , m , n) && vis[i+x[k]][j+y[k]] == 0){
                int temp=grid[i][j];
                for(int l=0;l<mp[temp][k].size();l++)
                {
                    if(mp[temp][k][l]==grid[i+x[k]][j+y[k]])
                    {
                        if(dfs(grid,i+x[k],j+y[k],m,n,vis,mp))
                            return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        // mapping all the paths to each other according to the start and the end nodes
        unordered_map<int,vector<vector<int>>> mp{{1,{{},{},{1,3,5},{1,4,6}}},
        {2,{{2,5,6},{2,3,4},{},{}}},{3,{{2,5,6},{},{},{1,4,6}}},{4,{{2,5,6},{},{1,3,5},{}}},
        {5,{{},{2,3,4},{},{1,4,6}}},{6,{{},{2,3,4},{1,3,5},{}}}};
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        return dfs(grid , 0 , 0 , m , n ,vis , mp);
    }
};
