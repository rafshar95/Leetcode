class Solution {
public:
    bool is_validated(std::vector<std::vector<char>>& board, int x, int y){
        for(int i = 0; i < 9; i++)
            if(i != x && board[i][y] == board[x][y])
                return false;
        for(int i = 0; i < 9; i++)
            if(i != y && board[x][y] == board[x][i])
                return false;
        int row = (x/3) * 3;
        int col = (y / 3) * 3;
        for(int i = row; i < row + 3; i++)
            for(int j = col; j < col + 3; j++)
                if((i != x || j != y) && board[i][j] == board[x][y])
                    return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.'){
                    if(!is_validated(board, i, j))
                        return false;
                }
        return true;
    }
};
