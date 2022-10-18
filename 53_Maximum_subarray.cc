class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int prior_dp = 0;
        int sum_prefix = 0;
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            cur_sum = nums[i];
            if(prior_dp > 0){
                cur_sum += prior_dp;
            }
            result = std::max(cur_sum, result);
            prior_dp = std::max(cur_sum , 0);
        }
        return result;
    }
};
