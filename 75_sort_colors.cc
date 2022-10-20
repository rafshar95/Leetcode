class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x = 0, y = 0, z = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                x++;
            if(nums[i] == 1)
                y++;
            if(nums[i] == 2)
                z++;
        }
        for(int i = 0; i < nums.size() ; i++){
            if(i < x)
                nums[i] = 0;
            else if(i >= x && i < x + y)
                nums[i] = 1;
            else nums[i] = 2;
        }
    }
};
