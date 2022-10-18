class Solution {
public:
    bool dp[100 + 1][30 + 1];
    void LearnCombinations(int target, int pos, std::vector<int>& unique_candidates, std::vector<int>& candidates_count, std::vector<int> &current_combination, std::vector<std::vector<int>> &results){
        if(pos == -1){
            if(target == 0){
                results.push_back(current_combination);
            }
            return;
        }
        if(dp[pos][target])
            LearnCombinations(target, pos - 1, unique_candidates, candidates_count, current_combination, results);
        for(int l = 1; l * unique_candidates[pos] <= target && l <= candidates_count[pos]; l++)
            if(dp[pos][target - unique_candidates[pos] * l]){
                for(int i = 1; i <= l; i++)
                    current_combination.push_back(unique_candidates[pos]);
                LearnCombinations(target - unique_candidates[pos] * l, pos - 1, unique_candidates, candidates_count, current_combination, results);
                for(int i = 1; i <= l; i++)
                    current_combination.pop_back();
            }


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<vector<int>> results;
        std::vector<int> current_combination, candidates_count, unique_candidates;
        std::sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i++){
            if(i == 0 || candidates[i] != candidates[i-1]){
                unique_candidates.push_back(candidates[i]);
                candidates_count.push_back(1);
            }
            else
                candidates_count.back()++;
        }
        dp[0][0] = true;
        for(int i = 0; i < unique_candidates.size(); i++){
            dp[i + 1][0] = true;
            for(int j = 1; j <= target; j++){
                if(dp[i][j])
                    dp[i+1][j] = true;
                for(int l = 1; l * unique_candidates[i] <= j && l <= candidates_count[i]; l++)
                    if(dp[i][j - unique_candidates[i] * l])
                        dp[i+1][j] = true;
            }
        }
        LearnCombinations(target, unique_candidates.size() - 1, unique_candidates, candidates_count, current_combination, results);


        return results;
    }

};
