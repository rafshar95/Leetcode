class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};
        if(numRows == 2)
            return {{1}, {1, 1}};
        std::vector<std::vector<int>> results = {{1}};
        for(int i = 1; i < numRows; i++){
            results.push_back({1});
            for(int j = 0; j < int(results[i - 1].size() - 1); j++){
                results[i].push_back(results[i - 1][j] + results[i - 1][j + 1]);
            }
            results[i].push_back(1);
        }
        return results;
    }
};
