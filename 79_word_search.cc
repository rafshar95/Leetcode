class Solution {
public:
    int cnt = 0;
    void MatchLetters(int cur_pos, int row, int col, std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& used, std::string word, bool& exists, std::vector<int>& dir_x, std::vector<int>& dir_y){
        if(exists)
            return;
        if(cur_pos == word.size() - 1){
            exists = true;
            return;
        }
        used[row][col] = true;
        for(int i = 0; i < 4; i++){
            int next_row = row + dir_x[i];
            int next_col = col + dir_y[i];
            if(next_row < 0 || next_col < 0 || next_row >= board.size() || next_col >= board[0].size())
            continue;
            if(board[next_row][next_col] != word[cur_pos + 1] || used[next_row][next_col])
                continue;
            MatchLetters(cur_pos + 1, next_row, next_col, board, used, word, exists, dir_x, dir_y);
        }
        used[row][col] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size()));
        bool exists = false;
        std::vector<int> dir_x = {1, -1, 0, 0};
        std::vector<int> dir_y = {0, 0, 1, -1};
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0])
                    MatchLetters(0, i, j, board, used, word, exists, dir_x, dir_y);
                if(exists)
                    return true;
            }
        return false;
    }
};
