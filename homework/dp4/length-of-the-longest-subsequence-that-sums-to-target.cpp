class Solution {
public:

    int solve(vector<int>&nums, int target, int ind, vector<vector<int>>&dp){
        if(target == 0) return 0;
        if(ind<0 || target<0) return -1e8;
        if(dp[ind][target] != -1) return dp[ind][target];

        int take = 1 + solve(nums, target-nums[ind], ind-1, dp);
        int notTake = 0 + solve(nums, target, ind-1, dp);

        return dp[ind][target] = max(take, notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        int ans = solve(nums, target, n-1, dp);
        return ans>0 ? ans : -1;
    }
};
