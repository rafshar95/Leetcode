class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        if(obstacleGrid[0][0] || obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1])
            return 0;
        std::memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 0; i < obstacleGrid.size(); i++)
            for(int j = 0; j < obstacleGrid[i].size(); j++){
                if(!obstacleGrid[i][j]){
                    if(i != 0)
                        dp[i][j] += dp[i - 1][j];
                    if(j != 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
