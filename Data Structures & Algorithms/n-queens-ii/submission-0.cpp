class Solution {
public:
    vector<vector<string>> ans;

    void f(int row, vector<string>& board, int& n, vector<int>& up, vector<int>& dr, vector<int>& dl){
        if(row == board.size()){
            ans.push_back(board);
            return;
        } 
        for(int col = 0; col < board.size(); col++){
            if(up[col] == 0 && dr[row+col] == 0 && dl[board.size()-1 + (col-row)] == 0){
                board[row][col] = 'Q';
                up[col] = 1;
                dr[row+col] = 1;
                dl[board.size()-1 + (col-row)] = 1;
                f(row+1, board, n, up, dr, dl);
                board[row][col] = '.';
                up[col] = 0;
                dr[row+col] = 0;
                dl[board.size()-1 + (col-row)] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> up(n, 0);
        vector<int> dr((2*n)-1, 0);
        vector<int> dl((2*n)-1, 0);
        f(0, board, n, up, dr, dl);
        return ans.size();
    }
};