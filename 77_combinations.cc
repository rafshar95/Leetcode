class Solution {
public:
    void FindAllCombinations(int pos, int n, int k, std::vector<std::vector<int>>& combinations, std::vector<int>& cur){
        if(pos == k){
            combinations.push_back(cur);
            return;
        }
        if(pos < k){
            for(int i = pos + 1; i <= n; i++){
                if(cur.size() == 0 || i > cur.back()){
                    cur.push_back(i);
                    FindAllCombinations(pos + 1, n, k, combinations, cur);
                    cur.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> cur;
        FindAllCombinations(0, n, k, combinations, cur);
        return combinations;
    }
};
