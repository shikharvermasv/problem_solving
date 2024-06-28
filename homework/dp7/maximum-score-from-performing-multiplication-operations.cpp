class Solution {
public:
    int solver(vector<int>& nums , int i , int m , vector<int>& mul , vector<vector<int>>& dp){
        int n=(nums.size()-1-(m-i));
        if(m >= mul.size()){
            return 0;
        }
        if(dp[i][m] != -1){
            return dp[i][m];
        }

        int temp1 = nums[i]*mul[m] + solver(nums , i+1 , m+1 , mul , dp);
        int temp2 = nums[n]*mul[m] + solver(nums , i , m+1 , mul , dp);

        return dp[i][m] = max(temp1 , temp2);
    }

    int maximumScore(vector<int>& nums, vector<int>& mul) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(mul.size()+1 , -1));
        return solver(nums , 0 , 0 , mul , dp);
    }
};
