class Solution {
public:

// -----------------recur -----------------//
    // int recursion(string& s , int i){
    //     if(s[i] >= '0'){
    //         return 0;
    //     }
    //     if(i == s.size()){
    //         return 1;
    //     }

    //     int ans = recursion(s , i+1);

    //     if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1]<='6'))){
    //         ans  += recursion(s , i+2);
    //     }
    //     return ans;
    // }


// -------------------memo-------------------//
    int recursion(string& s , int i , vector<int>& dp){
        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        if(i >= s.size()){
            return 1;
        }

        int ans = recursion(s , i+1 , dp);

        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1]<='6'))){
            ans  += recursion(s , i+2 , dp);
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n+1 , -1);
        return recursion(s , 0 ,dp);

    }
};
