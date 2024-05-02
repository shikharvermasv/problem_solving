class Solution {
public:
// change the circle houses to linear by including either 1st house or the last house;
// then check all the cases and have the maximum of it


    int robberyamount(vector<int>&nums ,int i , int n , vector<int>& dp){
        if(i > n){
            return 0;
        }
        if(dp[i] != INT_MIN){
            return dp[i];
        }
        int notTake =0;
        int take =0;

        notTake += 0+robberyamount(nums , i+1 , n , dp);

        take += nums[i] + robberyamount(nums , i+2 , n , dp);
        dp[i] = max(notTake , take);

        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n+1 , INT_MIN);
        vector<int> dp2(n+1 , INT_MIN);
        if(n==1){
            return nums[0];
        }

        int maxi;
        maxi = max(robberyamount(nums , 0 , n-2 , dp1) , robberyamount(nums , 1 , n-1 , dp2));
        return maxi;
    }
};
