class Solution {
public:
    void GetAllPermutation(std::vector<int>& nums, int pos, std::vector<std::vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i--){
            std::swap(nums[pos], nums[i]);
            GetAllPermutation(nums, pos + 1, res);
            std::swap(nums[pos], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        GetAllPermutation(nums, 0, res);
        return res;
    }
};
