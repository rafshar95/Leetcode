class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        std::vector<int> ans(nums.size(), 0);
        for(int i = nums.size() - 2; i >= 0; i--){
            ans[i] = INT_MAX;
            for(int j = 1; j <= nums[i] && i + j < nums.size() ; j++){
                if(ans[i + j] != INT_MAX)
                    ans[i] = std::min(ans[i], ans[i + j] + 1);
            }
        }
        return ans[0];
    }
};
