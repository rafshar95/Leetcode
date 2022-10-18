class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int pos = nums.size() - 1;
        for(int i = 0; i <= pos; i++){
            bool should_try_again = true;
            while(should_try_again){
                should_try_again = false;
                if(nums[i] > 0 && nums[i] <= pos + 1 && nums[nums[i] -  1] != nums[i]){
                    std::swap(nums[i], nums[nums[i] - 1]);
                    should_try_again = true;
                }
                if(i < pos && (nums[i] <= 0 || nums[i] > pos + 1 || (nums[nums[i] - 1] == nums[i] && i != nums[i] - 1))){
                    std::swap(nums[i], nums[pos]);
                    pos--;
                    should_try_again = true;
                }
            }
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i + 1)
                return i+1;
        return nums.size() + 1;
    }
};
