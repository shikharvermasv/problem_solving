class Solution {
public:
    bool check = true;
    void dfs(vector<vector<int>>& grid, int i, int j,int rotten){
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0 || i >= rows || j <0 || j>=cols || grid[i][j] == 0 || grid[i][j] == 1+ rotten)
            return ;
        if(grid[i][j]==1){
            check= true;
            grid[i][j] = rotten+1;
            return;
        }
        grid[i][j] = rotten+1;
        dfs(grid, i, j+1, rotten);
        dfs(grid, i, j-1, rotten);
        dfs(grid, i+1, j, rotten);
        dfs(grid, i-1, j, rotten);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int rotten = 2;
        int time = 0;
        
        while(check){
            check = false;
            time++;
            for(int i=0 ; i<rows; i++){
                for(int j=0; j<cols; j++){
                    
                    if(grid[i][j] == rotten){
                        dfs(grid,i,j, rotten);
                    }
                }
            }
            rotten ++;
        }
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(grid[i][j] == 1)
                    return -1;

        return time-1;
    }
};
