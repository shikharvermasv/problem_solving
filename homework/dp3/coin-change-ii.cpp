class Solution {
public:
    int recurssion(vector<int>& coins , int i , int n , int amount , vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(amount < 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = recurssion(coins , i , n , amount - coins[i] , dp);
        int nottake = recurssion(coins , i+1 , n , amount , dp);

        return dp[i][amount] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));
        return recurssion(coins , 0 , n , amount , dp);   
    }
};
