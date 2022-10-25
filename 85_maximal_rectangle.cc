class Solution {
public:

    bool IsSubMatrixOne(int row1, int row2, int col1, int col2, std::vector<std::vector<int>> &sum_prefix_matrix){
        if(row1 > row2 || col1 > col2)
            return false;
        int number_of_ones = sum_prefix_matrix[row2][col2];
        if(col1)
            number_of_ones -= sum_prefix_matrix[row2][col1 - 1];
        if(row1)
            number_of_ones -= sum_prefix_matrix[row1 - 1][col2];
        if(row1 && col1)
            number_of_ones += sum_prefix_matrix[row1 - 1][col1 - 1];
        return number_of_ones == (row2 - row1 + 1) * (col2 - col1 + 1);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        std::vector<std::vector<int>> sum_prefix_matrix(matrix.size(), std::vector<int> (matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                sum_prefix_matrix[i][j] = matrix[i][j] - '0';
                if(i)
                    sum_prefix_matrix[i][j] += sum_prefix_matrix[i - 1][j];
                if(j)
                    sum_prefix_matrix[i][j] += sum_prefix_matrix[i][j - 1];
                if(i && j)
                    sum_prefix_matrix[i][j] -= sum_prefix_matrix[i - 1][j - 1];
            }
        }
        int ans = 0;
        for(int col1 = 0; col1 < matrix[0].size(); col1++)
            for(int col2 = col1; col2 < matrix[0].size(); col2++){
                for(int row1 = 0, row2 = 0; row2 < matrix.size(); row2++){
                    if(!IsSubMatrixOne(row2, row2, col1, col2, sum_prefix_matrix))
                        while(row1 <= row2)
                            row1++;
                    else{
                        ans = std::max(ans, (row2 - row1 + 1) * (col2 - col1 + 1));
                    }
                }
            }
        return ans;
    }
};
