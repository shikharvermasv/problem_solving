class Solution {
public:
    int recurssion(int i , int j , int m , int n , vector<vector<int>>& dp){
        if(i>=m || j>= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = recurssion(i , j+1 , m , n , dp);
        ans += recurssion(i+1 , j , m , n , dp);

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return recurssion(0 , 0 , m , n , dp);
    }
};
