class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid, int i ,int j, int m, int n)
    {
        if(i == m-1 && j == n-1) return true;
        
        if(grid[i][j] == 0) return false;
        
        if(grid[i][j] == 1)
        {
            grid[i][j] = 0;
            return ((j > 0 && (grid[i][j-1] == 4 || grid[i][j-1] == 6 || grid[i][j-1] == 1) && dfs(grid,i,j-1,m,n)) ||
                    j < n-1 && (grid[i][j+1] == 3 || grid[i][j+1] == 5 || grid[i][j+1] == 1) && dfs(grid,i,j+1,m,n));
        }
        else if(grid[i][j] == 2)
        {
            grid[i][j] = 0;
            return ((i > 0 && (grid[i-1][j] == 3 || grid[i-1][j] == 4 || grid[i-1][j] == 2) && dfs(grid,i-1,j,m,n)) ||
                    i < m-1 && (grid[i+1][j] == 5 || grid[i+1][j] == 6 || grid[i+1][j] == 2) && dfs(grid,i+1,j,m,n));
        }
        else if(grid[i][j] == 3)
        {
            
            grid[i][j] = 0;
            return ((j > 0 && (grid[i][j-1] == 4 || grid[i][j-1] == 6 || grid[i][j-1] == 1) && dfs(grid,i,j-1,m,n)) ||
                    i < m-1 && (grid[i+1][j] == 5 || grid[i+1][j] == 6 ||grid[i+1][j] == 2) && dfs(grid,i+1,j,m,n));
        }
        else if(grid[i][j] == 4)
        {
            
            grid[i][j] = 0;
            return ((j < n-1 && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5) && dfs(grid,i,j+1,m,n)) ||
                    i < m-1 && (grid[i+1][j] == 5 || grid[i+1][j] == 6 || grid[i+1][j] == 2) && dfs(grid,i+1,j,m,n));
        }
        else if(grid[i][j] == 5)
        {
            
            grid[i][j] = 0;
            return ((j > 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6) && dfs(grid,i,j-1,m,n)) ||
                    i > 0 && (grid[i-1][j] == 3 || grid[i-1][j] == 4 || grid[i-1][j] == 2) && dfs(grid,i-1,j,m,n));
        
        }
        else if(grid[i][j] == 6)
        {
            
            grid[i][j] = 0;
            return ((j < n-1 && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5) && dfs(grid,i,j+1,m,n)) ||
                    i > 0 && (grid[i-1][j] == 4 || grid[i-1][j] == 3 || grid[i-1][j] == 2) && dfs(grid,i-1,j,m,n));
        
        }
        else
        {
            grid[i][j] = 0;    
            return false;
         }    
    }    
    
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        return dfs(grid,0,0,grid.size(), grid[0].size());
        
    }
};
