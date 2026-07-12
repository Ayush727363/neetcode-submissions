class Solution {
public:
    vector<vector<string>> ans;

    bool issafe(int row, int col, vector<string>& board){
        for(int i = row; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }
        for(int i=row, j=col; i>=0 && j<board.size(); i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void f(int row, vector<string>& board){
        if(row == board.size()){
            ans.push_back(board);
            return;
        } 
        for(int col = 0; col < board.size(); col++){
            if(issafe(row, col, board)){
                board[row][col] = 'Q';
                f(row+1, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        f(0, board);
        return ans;
    }
};
