class Solution {
public:
    bool dp[40 + 1][500 + 1];
    void ReturnCombinations(int target, int pos, std::vector<std::vector<int>> &results, std::vector<int> &combination, std::vector<int>& candidates){
        if(pos == -1){
            if(target == 0)
                results.push_back(combination);
            return;
        }
        for(int i = 0; i * candidates[pos] <= target; i++){
            if(dp[pos][target - i * candidates[pos]]){
                for(int j = 1; j <= i; j++)
                    combination.push_back(candidates[pos]);
                ReturnCombinations(target - i * candidates[pos], pos - 1, results, combination, candidates);
                for(int j = 1; j <= i; j++)
                    combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dp[0][0] = true;
        for(int i = 0; i < candidates.size(); i++){
            dp[i + 1][0] = true;
            for(int j = 1; j <= target; j++){
                if(dp[i][j] == true)
                    dp[i + 1][j] = true;
                else{
                    for(int l = 1; l * candidates[i] <= j; l++)
                        dp[i + 1][j] |= dp[i][j - l * candidates[i]];
                }
            }
        }
        std::vector<std::vector<int> > results;
        std::vector<int> combination;
        ReturnCombinations(target, candidates.size() - 1, results, combination, candidates);
        return results;
    }
};
