class Solution {
public:
    struct VectorIntHashFunction{
        std::size_t operator()(const std::vector<int>& values) const{
            std::size_t answer = 0;
            std::hash<int> hasher;
            for(auto &value: values){
                answer ^= hasher(value) + (answer << 6) + (answer >> 2) + 0x9e3779b9;
            }
            return answer;
        }
    };
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_set<std::vector<int>, VectorIntHashFunction> subsets;
        std::vector<int> cur_subset;
        for(int i = 0; i < (1 << nums.size()); i++){
            cur_subset.clear();
            for(int j = 0; j < nums.size(); j++)
                if((1 << j) & i)
                    cur_subset.push_back(nums[j]);
            subsets.insert(cur_subset);
        }
        std::vector<std::vector<int>> result;
        for(std::unordered_set<std::vector<int>>::iterator it = subsets.begin(); it != subsets.end(); it++)
            result.push_back(*it);
        return result;
    }
};
