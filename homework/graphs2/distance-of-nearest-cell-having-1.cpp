class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    void dfs(int i , int j ,int r, int c , vector<vector<int>>& grid , vector<vector<int>>& ans, int count){
        if(i < 0 || j<0 || i>= r || j >= c || count >= ans[i][j]){
            return;
        }
        ans[i][j] = count;
        dfs(i + 1 , j , r , c, grid, ans, count + 1);
        dfs(i - 1 , j , r , c, grid, ans, count + 1);
        dfs(i , j + 1 , r , c, grid, ans, count + 1);
        dfs(i , j - 1 , r , c, grid, ans, count + 1);
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int r = grid.size();
        int c = grid[0].size();
	    vector<vector<int>>ans(r, vector<int>(c, INT_MAX));
	    for(int i=0 ; i<grid.size() ; i++){
	        for(int j=0 ; j<grid[0].size() ; j++){
	            if(grid[i][j] == 1){
	                dfs(i , j , r , c, grid , ans , 0);
	            }
	        }
	    }
	    return ans;
	}
};
