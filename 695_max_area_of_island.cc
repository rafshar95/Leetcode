class Solution {
public:

    std::pair<int, int> GetRoot(int row, int col, std::vector<std::vector<std::pair<int,int>>>& parent){
        if(parent[row][col] == std::make_pair(-1, -1))
            return {row, col};
        return parent[row][col] = GetRoot(parent[row][col].first, parent[row][col].second, parent);
    }
    void Merge(int row_1, int col_1, int row_2, int col_2, std::vector<std::vector<std::pair<int,int>>>& parent, std::vector<std::vector<int>>& rank){
        std::pair<int, int> root_1 = GetRoot(row_1, col_1, parent);
        std::pair<int, int> root_2 = GetRoot(row_2, col_2, parent);
        if(root_1 == root_2)
            return;
        if(rank[root_1.first][root_1.second] < rank[root_2.first][root_2.second])
            std::swap(rank[root_1.first][root_1.second], rank[root_2.first][root_2.second]);
        rank[root_1.first][root_1.second] += rank[root_2.first][root_2.second];
        parent[root_2.first][root_2.second] = root_1;
    }
    void MergeNeighbors(int row, int col, std::vector<std::vector<int>>& grid, std::vector<std::vector<std::pair<int,int>>>& parent, std::vector<std::vector<int>>& rank){
        int n = grid.size();
        int m = grid[0].size();
        if(row != 0 && grid[row - 1][col])
            Merge(row, col, row - 1, col, parent, rank);
        if(row != n - 1 && grid[row + 1][col])
            Merge(row, col, row + 1, col, parent, rank);
        if(col != 0 && grid[row][col - 1])
            Merge(row, col, row, col - 1, parent, rank);
        if(col != m - 1 && grid[row][col + 1])
            Merge(row, col, row, col + 1, parent, rank);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<std::pair<int, int>>> parent(n, std::vector<std::pair<int, int>> (m, {-1, -1}));
        std::vector<std::vector<int>> rank(n, std::vector<int> (m, 1));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    MergeNeighbors(i, j, grid, parent, rank);
        int max_area = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    max_area = std::max(max_area, rank[i][j]);
        return max_area;
    }
};
