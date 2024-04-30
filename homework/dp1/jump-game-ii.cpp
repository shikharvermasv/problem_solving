class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(nums.size()+1,INT_MAX);
        dp[0] = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(i+nums[i] >= n-1){
                dp[n-1] = min(dp[i]+1 , dp[n-1]);
                break;
            }
            for(int j=i+1 ; j<=i+nums[i] ; j++){
                dp[j] = min(dp[j] , dp[i]+1);
            }
        }
        return dp[n-1];
    }
};
