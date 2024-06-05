class Solution{
public:
    
    int pass(vector<vector<int>> &m, int i, int j, int row , int col , vector<vector<int>> &Cost , vector<vector<int>>& dp){
        if (i == row - 1 and (j >= 0 and j <= col - 1)){
            return m[i][j];
        }
        if (i == row || (j < 0 || j == col)){
            return 6000;  
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 6000;
        for (int ii = 0; ii < col; ii++)   {
            ans = min(ans, (m[i][j] + Cost[m[i][j]][ii] + pass(m, i + 1, ii, row , col , Cost , dp)));
        }
        return dp[i][j] = ans;
    }

    
    int minPathCost(vector<vector<int>> &matrix, vector<vector<int>> &moveCost){
        int ans = INT_MAX;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row , vector<int>(col , -1));
        for (int i = 0; i < col; i++){
            ans = min(ans, pass(matrix, 0, i, row , col, moveCost ,dp));
			
        }
        return ans;
    }
};
