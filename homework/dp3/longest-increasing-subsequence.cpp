class Solution {
public:
//  recursive approach (TLE)

    // int recursion(vector<int>& nums , int prev  , int current){
    //     // base condition
    //     if(current >= nums.size() ){
    //         return 0;
    //     }
    //     int take =0;
    //     int nottake =0;
    //     if(prev == -1 || nums[prev] < nums[current]){
    //         take = 1+recursion(nums , current , current+1);
    //     }
    //     nottake = recursion(nums , prev , current +1);

    //     return max(take , nottake);

    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int current = 0;
    //     int prev = -1;
    //     return recursion(nums, prev , current);

    // }

// memoization solution
    // int memo(int prev , int curr , vector<int>& nums , vector<vector<int>>& dp){
    //     if( curr >= nums.size()){
    //         return 0;
    //     }
    //     if(prev != -1 && dp[prev][curr] != -1){
    //         return dp[prev][curr];
    //     }

    //     int take = 0;
    //     int nottake =0;
    //     if(prev == -1 || nums[prev] < nums[curr]){
    //         take = 1+ memo(curr , curr+1 , nums , dp);
    //     }
    //     nottake = memo(prev , curr+1 , nums , dp);

    //     return max(take , nottake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
    //     return memo(-1 , 0 , nums , dp);
    // }


// tabulation
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
    //     for(int i=n-1 ; i>=0 ; i--){
    //         for(int j=i ; j>=0 ; j--){
    //             int take = 0;
    //             int nottake =0;
                
    //             if(j==0 || nums[i] > nums[j-1]){
    //                 take = 1+ dp[i+1][i+1];
    //             }
    //             nottake = dp[i+1][j];
    //             dp[i][j] = max(take,nottake);
    //         }
    //     }
    //     return dp[0][0];
    // }


    int binarysearch(int a ,vector<int>&ans){
        int left = 0;
        int right = ans.size() -1;
        int temp;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(ans[mid] < a){
                left = mid+1;
            }
            else{
                temp = mid;
                right = mid-1;
            }
        }
        return temp;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i = 1;i<n;i++)
        {
            if(nums[i]>ans[ans.size()-1])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int idx = binarysearch(nums[i],ans);
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};
