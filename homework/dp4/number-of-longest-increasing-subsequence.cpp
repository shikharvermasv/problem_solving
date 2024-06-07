class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();

        vector<pair<int,int>> dp(n,{1,1});

        int maxi=0,cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[i]>nums[j]){
                    if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                    else if(dp[i].first<dp[j].first+1){
                        dp[i].second=dp[j].second;
                        dp[i].first=dp[j].first+1;
                    }
                }
            }

            if(dp[i].first==maxi) cnt+=dp[i].second;

            else if(dp[i].first>maxi){
                maxi=dp[i].first;
                cnt=dp[i].second;
            }
        }

        return cnt;
    }
};
