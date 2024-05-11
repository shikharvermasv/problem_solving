class Solution {
public:
    int dp[1001][1001];
    int solve(string &a,string &b,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(a[n-1]==b[m-1]){
            return dp[n][m] = 1 + solve(a,b,n-1,m-1);
        }
        return dp[n][m] = max(solve(a,b,n-1,m), solve(a,b,n,m-1));
    }
    
    string shortestCommonSupersequence(string a, string b) {
        memset(dp,-1,sizeof(dp));
        int n = a.length();
        int m = b.length();
        int size = solve(a,b,n,m);
        string ans = "";
        int i = n,j = m;

        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans += a[i-1];
                i--,j--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                ans += b[j-1];
                j--;
            }else{
                ans += a[i-1];
                i--;
            }
        }

        while(i>0){
            ans += a[i-1];
            i--;
        }
        while(j>0){
            ans += b[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
