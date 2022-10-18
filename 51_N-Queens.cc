class Solution {
public:
    void FindAllSolutions(int row, std::vector<std::string>& cur_result, std::vector<std::vector<std::string>>& all_results, std::vector<bool>& leading_diagonal, std::vector<bool>& counter_diagonal, std::vector<bool>& column, std::vector<std::string>& queen_rows){
    if(row == column.size()){
        all_results.push_back(cur_result);
        return;
    }
    for(int col = 0; col < queen_rows.size(); col++){
        if(!column[col] && !counter_diagonal[col + row] && !leading_diagonal[col - row + queen_rows.size() - 1]){
            column[col] = true;
            counter_diagonal[col + row] = true;
            leading_diagonal[col - row + queen_rows.size() - 1] = true;
            cur_result.push_back(queen_rows[col]);
            FindAllSolutions(row + 1, cur_result, all_results, leading_diagonal, counter_diagonal, column, queen_rows);
            column[col] = false;
            counter_diagonal[col + row] = false;
            leading_diagonal[col - row + queen_rows.size() - 1] = false;
            cur_result.pop_back();
        }
    }
    }
    vector<vector<string>> solveNQueens(int n) {
        std::vector<bool> leading_diagonal(2 * n - 1, 0), counter_diagonal(2 * n - 1, 0);
        std::vector<bool> column(n, 0);
        std::vector<std::string> queen_rows(n, std::string(n, '.'));
        for(int i = 0; i < queen_rows.size(); i++)
            queen_rows[i][i] = 'Q';
        std::vector<std::vector<std::string>> all_results;
        std::vector<std::string> cur_result;
        FindAllSolutions(0, cur_result, all_results, leading_diagonal, counter_diagonal, column, queen_rows);
        return all_results;
    }
};
