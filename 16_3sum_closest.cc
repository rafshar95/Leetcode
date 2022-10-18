class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        const int kWorstPossibleSum = 1000 * 1000;
        int best_sum = kWorstPossibleSum;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size() - 1; j++){
                std::vector<int>::iterator low = std::lower_bound(nums.begin() + j + 1, nums.end(), target - nums[i] - nums[j]);
                if(low != nums.end()){
                    int sum = *low + nums[i] + nums[j];
                    if(std::abs(sum - target) < std::abs(best_sum - target))
                        best_sum = sum;
                }
                if(low - nums.begin() != j + 1){
                    int sum = *(--low) + nums[i] + nums[j];
                    if(std::abs(sum - target) < std::abs(best_sum - target))
                        best_sum = sum;
                }
            }
        return best_sum;
    }
};
