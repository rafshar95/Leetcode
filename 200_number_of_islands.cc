class Solution {
public:
    void dfs(int row, int col, std::vector<std::vector<char>>& grid){
        std::vector<std::pair<int, int>> neighbors = {{row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1}};
        grid[row][col] = '0';
        for(int i = 0; i < neighbors.size(); i++)
            if(neighbors[i].first >= 0 && neighbors[i].first < grid.size() && neighbors[i].second >= 0 && neighbors[i].second < grid[0].size() && grid[neighbors[i].first][neighbors[i].second] == '1'){
                dfs(neighbors[i].first, neighbors[i].second, grid);
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt_island = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == '1'){
                    cnt_island++;
                    dfs(i, j, grid);
                }
        return cnt_island;
    }
};
