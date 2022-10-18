class Solution {
public:
    void FindAllSolutions(int row, std::vector<bool>& leading_diagonal, std::vector<bool>& counter_diagonal, std::vector<bool>& column, int& total_n_queens){
        if(row == column.size()){
            total_n_queens++;
            return;
        }
        for(int col = 0; col < column.size(); col++){
            if(!column[col] && !leading_diagonal[col - row + column.size() - 1] && !counter_diagonal[col + row]){
                column[col] = true;
                leading_diagonal[col - row + column.size() - 1] = true;
                counter_diagonal[col + row] = true;
                FindAllSolutions(row + 1, leading_diagonal, counter_diagonal, column, total_n_queens);
                column[col] = false;
                leading_diagonal[col - row + column.size() - 1] = false;
                counter_diagonal[col + row] = false;
            }
        }
    }
    int totalNQueens(int n) {
        std::vector<bool> leading_diagonal(2 * n - 1, 0), counter_diagonal(2 * n - 1, 0), column(n, 0);
        int total_n_queens = 0;
        FindAllSolutions(0, leading_diagonal, counter_diagonal, column, total_n_queens);
        return total_n_queens;
    }
};
