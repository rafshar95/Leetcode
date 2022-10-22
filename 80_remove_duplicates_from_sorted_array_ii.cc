class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int cnt_increment = 0;
            if(i + 1 != nums.size() && nums[i] == nums[i + 1])
                cnt_increment = 1;
            if(cnt <= 2){
                std::swap(nums[i], nums[res]);
                res++;
            }
            if(cnt_increment)
                cnt++;
            else
                cnt = 1;
        }
        return res;
    }
};
