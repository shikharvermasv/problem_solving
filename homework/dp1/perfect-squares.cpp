class Solution {
public:
    int numSquares(int n) {
        // memorization
        // vector<int> dp(n+1 , -1);
        // if(n==0){
        //     return 0;
        // }
        // if(dp[n] != -1){
        //     return dp[n];
        // }
        // int res = INT_MAX;
        // for(int i=1; i*i <= n; i++){
        //     int cnt = 1+numSquares(n - i*i);
        //     res = min(res, cnt);
        // }
        // return dp[n] = res;

        // tabulation
        vector<int> dp(n+1 , INT_MAX);
        dp[0] = 0;
        for(int i=1; i<= n; i++){
            for(int j=1 ; j*j<=i ; j++){
                dp[i] = min(dp[i] , 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
