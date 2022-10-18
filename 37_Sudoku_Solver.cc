class Solution {
public:
    std::vector<std::vector<char>> solution;
    std::vector<std::pair<int, int>> all_neighbors[9][9];
    int invalid_choices[9][9][9];
    std::vector<std::pair<int,int>> FindNeighbors(int x, int y){ // find all neighbors for node(x, y)
        std::set<std::pair<int, int>> neighbors;
        for(int i = 0; i < 9; i++){
            if(i != y)
                neighbors.insert(std::make_pair(x, i));
            if(i != x)
                neighbors.insert(std::make_pair(i, y));
        }
        for(int i = (x / 3) * 3; i < (x / 3 + 1) * 3; i++)
            for(int j = (y / 3) * 3; j < (y / 3 + 1) * 3; j++){
                if(i != x || j != y)
                    neighbors.insert(std::make_pair(i, j));
            }
        std::vector<std::pair<int, int>> res;
        for(std::set<std::pair<int, int>>::iterator it = neighbors.begin(); it != neighbors.end(); it++){
            res.push_back(*it);
        }
        neighbors.clear();
        return res;
    }
    void InitInvalidChoices(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] == '.')
                    for(int l = 0; l < all_neighbors[i][j].size(); l++){
                        int x = all_neighbors[i][j][l].first;
                        int y = all_neighbors[i][j][l].second;
                        if(board[x][y] != '.')
                            invalid_choices[i][j][board[x][y] - '1']++;
                    }
    }
    void RecursiveSolveSodoku(vector<vector<char>>& board, int x, int y){
        int next_x = -1;
        int next_y = -1;
        if(y < 8){
            next_x = x;
            next_y = y + 1;
        }
        else if(x < 8){
            next_x = x + 1;
            next_y = 0;
        }
        if(board[x][y] == '.'){
            for(int i = 0; i < 9; i++){
                if(!invalid_choices[x][y][i]){
                    board[x][y] = char(i + '1');
                    if(next_x == -1){
                        solution = board;
                        return;
                    }
                    for(int j = 0; j < all_neighbors[x][y].size(); j++){
                        int pos_x = all_neighbors[x][y][j].first;
                        int pos_y = all_neighbors[x][y][j].second;
                        if(board[pos_x][pos_y] == '.')
                            invalid_choices[pos_x][pos_y][i]++;
                    }
                    RecursiveSolveSodoku(board, next_x, next_y);
                    for(int j = 0; j < all_neighbors[x][y].size(); j++){
                        int pos_x = all_neighbors[x][y][j].first;
                        int pos_y = all_neighbors[x][y][j].second;
                        if(board[pos_x][pos_y] == '.')
                            invalid_choices[pos_x][pos_y][i]--;
                    }

                }
            }
            board[x][y] = '.';
        }
        else{
            if(next_x == -1){
                solution = board;
            }
            else
                RecursiveSolveSodoku(board, next_x, next_y);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                all_neighbors[i][j] = FindNeighbors(i, j);
        InitInvalidChoices(board);
        RecursiveSolveSodoku(board, 0, 0);
        board = solution;
    }
};
