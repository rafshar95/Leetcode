class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_column = false;
        bool first_row = false;
        for(int i = 0; i < matrix.size(); i++)
            if(!matrix[i][0])
                first_column = true;
        for(int i = 0; i < matrix[0].size(); i++)
            if(!matrix[0][i])
                first_row = true;
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for(int i = 1; i < matrix.size(); i++)
            if(matrix[i][0] == 0)
                for(int j = 1; j < matrix[i].size(); j++)
                    matrix[i][j] = 0;
        for(int i = 1; i < matrix[0].size(); i++)
            if(matrix[0][i] == 0)
                for(int j = 1; j < matrix.size(); j++)
                    matrix[j][i] = 0;
        if(first_row)
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        if(first_column)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};
