class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans_cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 == nums.size() || nums[i] != nums[i + 1]){
                std::swap(nums[ans_cnt], nums[i]);
                ans_cnt++;
            }
        }
        return ans_cnt;
    }
};
