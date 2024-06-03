class Solution {
public:

    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& memo) {
        if (m < 0 || n < 0){
            return 0;
        } 
        if (grid[m][n] == 1){
            return 0;
        }
        if (m == 0 && n == 0){
            return 1;
        }
        if(memo[m][n] != -1){
            return memo[m][n];
        }
        return memo[m][n] = solve(grid, m-1, n, memo) + solve(grid, m, n-1, memo); 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(obstacleGrid, m-1, n-1, memo);
    }
};
