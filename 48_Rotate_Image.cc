class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size() / 2; i++){
            for(int j = i; j < matrix.size() - i - 1; j++){
                int n = matrix.size() - 1;
                int upper_left = matrix[i][j];
                int upper_right = matrix[j][n - i];
                int lower_right = matrix[n - i][n - j];
                int lower_left = matrix[n - j][i];
                matrix[i][j] = lower_left;
                matrix[j][n - i] = upper_left;
                matrix[n - i][n - j] = upper_right;
                matrix[n - j][i] = lower_right;
            }
        }
    }
};
