class Solution {
public:
    int recurssion(vector<vector<int>>&grid , int i , int j , int n , int m , vector<vector<int>>& dp){
        if(i >= n || j >= m) return 1e9;
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        if(dp[i][j]  != -1){
            return dp[i][j];
        }
        // now we are moving in two directions so
        // we will have 2 recursive calls (one for i+1) (other for j+1)
        // we are moving in 2 directions right and down
        int right = grid[i][j];
        int down  = grid[i][j];

        right += recurssion(grid , i+1 , j , n , m , dp);
        down += recurssion(grid , i , j+1 , n , m , dp);

        return dp[i][j] = min(right , down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return recurssion(grid ,0 , 0 , n , m , dp);
    }
};
