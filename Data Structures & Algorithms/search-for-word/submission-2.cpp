class Solution {
public:

    bool f(int it, int i, int j, vector<vector<char>>& board, string& word){
        if(board[i][j] != word[it]) return false;
        if(it == word.size()-1) return true;
        
        char ch = board[i][j];
        board[i][j] = '#';

        bool found = (i > 0 && f(it+1, i-1, j, board, word)) ||
            (j > 0 && f(it+1, i, j-1, board, word)) ||
            (i < board.size()-1 && f(it+1, i+1, j, board, word)) ||
            (j < board[0].size()-1 && f(it+1, i, j+1, board, word));

        board[i][j] = ch;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(board[i][j] == word[0] && f(0, i, j, board, word))
                    return true;
        return false;
    }
};
