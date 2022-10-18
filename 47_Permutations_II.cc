class Solution {
public:
    struct hashFunction
      {
         size_t operator()(const vector<int> &myVector) const
         {
             std::hash<int> hasher;
             size_t answer = 0;
             for (int i : myVector)
            {
                answer ^= hasher(i) + 0x9e3779b9 +
                                  (answer << 6) + (answer >> 2);
           }
           return answer;
       }
   };
    void GetAllUniquePermutations(std::vector<int>& nums, int pos, std::vector<std::vector<int>>& res, std::unordered_set<std::vector<int>, hashFunction>& unique_permutations){
        if(pos == nums.size()){
            if(unique_permutations.find(nums) == unique_permutations.end()){
                unique_permutations.insert(nums);
                res.push_back(nums);
            }
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            std::swap(nums[i], nums[pos]);
            GetAllUniquePermutations(nums, pos + 1, res, unique_permutations);
            std::swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::unordered_set<std::vector<int>, hashFunction> unique_permutations;
        GetAllUniquePermutations(nums, 0, res, unique_permutations);
        return res;
    }
};
