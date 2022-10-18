class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int dis_from_end = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == val){
                dis_from_end++;
                std::swap(nums[i], nums[nums.size() - dis_from_end]);
            }
        }
        return nums.size() - dis_from_end;
    }
};
