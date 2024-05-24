class Solution
{
public:
    int recursion(int n){
        if(n==0){
            return 1;
        }
        int ans1 = recursion(n-1);
        int ans2 =0;
        if(n>=2){
            ans2 = recursion(n-2)*(n-1);
        }
        return ans1+ans2;
    }

    int countFriendsPairings(int n) 
    { 
        // code here
        return recursion(n);
    }
};    


class Solution
{
public:
int mod = 1000000007;
    int countFriendsPairings(int n) 
    { 
        if(n<=2) return n;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1] % mod + (dp[i-2] * 1ll * (i-1)) % mod)%mod;
        }
        return dp[n];
    }
};    
