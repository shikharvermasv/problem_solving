class Solution {
public:
    void dfs(vector<vector<char>>& board , int i , int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != 'O'){
            return ;
        }
        board[i][j] = 'C'; // marking the boundry element and the connecting element

        dfs(board , i+1 , j);
        dfs(board , i-1 , j);
        dfs(board , i , j+1);
        dfs(board , i , j-1);
    }
    void solve(vector<vector<char>>& board) {
        
        if(board.size() == 0){
            return ;
        }

        for(int i=0 ; i<board.size() ; i++){
            if(board[i][0] == 'O'){
                dfs(board , i , 0);
            }
            if(board[i][board[0].size()-1] == 'O'){
                dfs(board , i , board[0].size()-1);
            }
        }

        for(int i=0 ; i<board[0].size() ; i++){
            if(board[0][i] == 'O'){
                dfs(board , 0 , i);
            }
            if(board[board.size()-1][i] == 'O'){
                dfs(board , board.size()-1 , i);
            }
        }

        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'C')
                    board[i][j] = 'O';
            }
        }
    }
};
