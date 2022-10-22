class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> results;
        std::vector<int> cur;
        for(int i = 0; i < (1 << nums.size()); i++){
            cur.clear();
            for(int j = 0; j < nums.size(); j++)
                if((1 << j) & i)
                    cur.push_back(nums[j]);
            results.push_back(cur);
        }
        return results;
    }
};
