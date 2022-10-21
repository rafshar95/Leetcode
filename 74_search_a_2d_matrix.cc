class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while(left < right){
            int mid = (left + right) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] > target)
                right = mid;
            else
                left = mid + 1;
        }
        int row = left / m;
        int col = left % m;
        if(matrix[row][col] == target)
            return true;
        return false;
    }
};
