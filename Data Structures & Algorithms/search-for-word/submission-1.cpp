class Solution {
public:

    bool f(int it, int i, int j, vector<vector<char>>& board, string& word){
        if(board[i][j] != word[it]) return false;
        if(it == word.size()-1) return true;
        
        char ch = board[i][j];
        board[i][j] = '#';

        bool a = 0, b= 0, c= 0, d= 0;
            if(i>0) a = f(it+1, i-1, j, board, word);
            if(j>0) b = f(it+1, i, j-1, board, word);
            if(i< board.size()-1) c = f(it+1, i+1, j, board, word);
            if(j< board[0].size()-1) d = f(it+1, i, j+1, board, word);

        board[i][j] = ch;
        return a || b || c || d;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(board[i][j] == word[0] && f(0, i, j, board, word))
                    return true;
        return false;
    }
};
