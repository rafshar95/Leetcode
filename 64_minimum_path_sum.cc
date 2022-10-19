class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[2][201];
        std::memset(dp, 0, sizeof dp);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                dp[i % 2][j] = grid[i][j];
                if(i != 0 && j != 0){
                    dp[i % 2][j] += std::min(dp[i % 2][j - 1], dp[(i + 1) % 2][j]);
                }
                else if(i != 0){
                    dp[i % 2][j] += dp[(i + 1) % 2][j];
                }
                else if(j != 0){
                    dp[i % 2][j] += dp[i % 2][j - 1];
                }
            }
        }
        return dp[(grid.size() + 1) % 2][grid[0].size() - 1];
    }
};
