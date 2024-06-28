class Solution {
public:
// ---------------- rec ------------//
    // int recursion(string word1, string word2 , int i , int j){
    //     if(i == 0 && j == 0){
    //         return 0;
    //     }
    //     if(i == 0 ){
    //         return j;
    //     }
    //     if(j == 0){
    //         return i;
    //     }

    //     if(word1[i-1] == word2[j-1]){
    //         return recursion(word1 , word2 , i-1 , j-1);
    //     }
    //     else{
    //         int opreplace = recursion(word1 , word2 , i-1 , j-1);
    //         int opadd = recursion(word1 , word2 , i , j-1);
    //         int opremove = recursion(word1 , word2 , i-1 , j);

    //         return min(opreplace , min(opadd , opremove))+1;
    //     }
    // }

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     return recursion (word1 , word2 , n , m);
    // }
// ------------- memo + rec ------------------//

    // int recursion(string word1, string word2 , int i , int j , vector<vector<int>>& dp){
    //     if(i == 0 && j == 0){
    //         return 0;
    //     }
    //     if(i == 0 ){
    //         return j;
    //     }
    //     if(j == 0){
    //         return i;
    //     }

    //     if(word1[i-1] == word2[j-1]){
    //         return dp[i][j] = recursion(word1 , word2 , i-1 , j-1 , dp);
    //     }
    //     else{
    //         int opreplace = recursion(word1 , word2 , i-1 , j-1 ,dp)+1;
    //         int opadd = recursion(word1 , word2 , i , j-1 ,dp)+1;
    //         int opremove = recursion(word1 , word2 , i-1 , j ,dp)+1;

    //         return dp[i][j] = min(opreplace , min(opadd , opremove));
    //     }
    // }

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
    //     return recursion (word1 , word2 , n , m , dp);
    // }
// ------------ dp --------------//

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();

    //     vector<vector<int>>dp(n+1,vector<int>(m+1));
    //     dp[0][0] = 0;

    //     for(int i = 1;i<=m;i++){
    //         dp[0][i] = i;
    //     }
    //     for(int i = 1;i<=n;i++){
    //         dp[i][0] = i;
    //     }
        
    //     for(int i= 1;i<=n;i++){
    //         for(int j = 1;j<=m;j++){

    //             if(word1[n-i]==word2[m-j]){
    //                 dp[i][j] = dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

//--------------- space optimization ----------- //
    int minDistance(string word1, string word2) {
        
    }
};
