class Solution{
public:
    // -------------------recursion solution ----------------//
    // int  minop(int arr[]  , int s , int e){
    //     if(s == e){
    //         return 0;
    //     }
    //     if(s+1 == e){
    //         return arr[s-1] * arr[s] * arr[e];
    //     }
    //     int mini = INT_MAX;
    //     for(int i=s ; i<e ; i++){
    //         int op1 = minop(arr , s , i);
    //         int op2 = minop(arr , i+1 , e);
    //         int op3 = arr[s-1]*arr[i]*arr[e];
    //         int minops = op1 + op2 + op3;
    //         mini = min(mini , minops);
    //     }
    //     return mini;
    // }
    
    // ----------------memo---------------------//
    // int  minop(int arr[]  , int s , int e , vector<vector<int>>&dp){
    //     if(s == e){
    //         return 0;
    //     }
    //     if(dp[s][e] != -1){
    //         return dp[s][e];
    //     }
    //     int mini = INT_MAX;
    //     for(int i=s ; i<e ; i++){
    //         int op1 = minop(arr , s , i , dp);
    //         int op2 = minop(arr , i+1 , e , dp);
    //         int op3 = arr[s-1]*arr[i]*arr[e];
    //         int minops = op1 + op2 + op3;
    //         mini = min(mini , minops);
    //     }
    //     return dp[s][e] = mini;
    // }
    
    int matrixMultiplication(int n, int arr[]){
        // code here
        // vector<vector<int>> dp(n , vector<int>(n,-1));
        // return minop(arr, 1 , n-1 , dp);
        
        vector<vector<int>> dp(n , vector<int>(n));
        
        for(int i=0 ; i<n ; i++){
            dp[i][i] = 0;
        }
        
        for(int i=n-1 ; i>=1 ; i--){
            for(int j=i+1 ; j<n ; j++){
                int mini = INT_MAX;
                for(int k = i ; k<j ; k++){
                    int minops = arr[i-1]* arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini , minops);
                }
                
                dp[i][j]= mini;
            }
        }
        return dp[1][n-1];
    }
};  
