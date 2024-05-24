class Solution {
public:
    long long mod = 1000000007;
    int recursion(string& s , int i , int n , vector<long long>& dp){
        if(i == n){
            return 1;
        }

        if(s[i] == '0'){
            return 0;//invalid;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        long long ans = 0 ;
        long long comb;

        if(s[i] == '*'){
            comb = 9;
        }
        else{
            comb = 1;
        }

        ans += comb * recursion(s , i+1 , n , dp);

        if(i < n-1){
            long long comb2 = 0;
            char curr = s[i];
            char curr2 = s[i+1];

            if(curr == '*'){
                if(curr2 == '*'){
                    comb2 = 15;
                }
                else{
                    if(curr2 <= '6'){
                        comb2 =2;
                    }
                    else{
                        comb2 =1;
                    }
                }
            }

            if(curr == '1' || curr == '2'){
                if(curr2 == '*'){
                    if(curr == '1'){
                        comb2 = 9;
                    }
                    if(curr == '2'){
                        comb2 = 6;
                    }
                }
                else{
                    if(s[i] == '1' || (s[i] == '2' && s[i+1]<='6')){
                        comb2 = 1;
                    }
                }
            }

            if(comb2){
                ans += comb2*recursion(s , i+2 , n , dp);
            }
        }

        return dp[i] = ans%mod;

    }

    int numDecodings(string s) {
        int n = s.size();
        vector<long long > dp(n+1 , -1);
        return recursion(s ,  0 , n , dp);

    }
};
