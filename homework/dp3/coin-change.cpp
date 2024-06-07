class Solution {
public:
    int recurssion(vector<int>& coins , int amount , int i , vector<vector<int>>& dp){
        if(i==0){
            if(amount % coins[i] == 0){
                return amount/coins[i];
            }
            else{
                return 1e9;
            }
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1 + recurssion(coins , amount - coins[i] , i , dp);
        }

        int nottake = recurssion(coins , amount , i-1 , dp);

        return dp[i][amount] = min(take , nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1 , -1));
        int ans = recurssion(coins , amount , n-1 , dp);

        if(ans == 1e9){
            return -1; // if any of the combination cannot make the amount
        }
        return ans;
    }
};
