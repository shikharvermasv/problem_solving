class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<vector<int>> dp(r , vector<int>(c,0));

        // for the value of the last cell fo the matrix
        //base case
        if(dungeon[r-1][c-1] < 0 ){
            dp[r-1][c-1] =  abs(dungeon[r-1][c-1])+1;
        }
        else{
            dp[r-1][c-1] = 1;
        }

        for(int i=r-1 ; i>=0 ; --i){
            for(int j=c-1 ; j>=0 ; --j){
                if(i == r-1 && j == c-1){
                    continue;
                }
                // last row element
                if(i == r-1){
                    if(dungeon[i][j] <= 0){
                        dp[i][j] = abs(dungeon[i][j]) + dp[i][j+1];
                    }
                    else{
                        if (dungeon[i][j] >= dp[i][j+1]) {
                            dp[i][j] = 1;
                        } else {
                            dp[i][j] = dp[i][j+1] - dungeon[i][j];
                        }
                    }
                }
                // for last column elements in the matrix
                else if(j == c-1){
                    if(dungeon[i][j] <= 0){
                        dp[i][j] = abs(dungeon[i][j]) + dp[i+1][j];
                    }
                    else{
                        if (dungeon[i][j] >= dp[i+1][j]) {
                            dp[i][j] = 1;
                        } else {
                            dp[i][j] = dp[i+1][j] - dungeon[i][j];
                        }
                    }
                }

                // any other random cell
                // we are taking min because we need to traverse on the cell which reqiered minimum health of dungeon
                else if( i < r-1 && j < c-1){
                    int mini = min(dp[i][j+1], dp[i+1][j]);
                    if(dungeon[i][j] <= 0){
                        dp[i][j] = abs(dungeon[i][j]) + mini;
                    }
                    else{
                        if (dungeon[i][j] < mini) {
                            dp[i][j] = mini - dungeon[i][j];
                        } else {
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }
        return dp[0][0];
    }
};
