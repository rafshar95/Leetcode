class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_access = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > max_access)
                return false;
            max_access = std::max(max_access, i + nums[i]);
        }
        return true;
    }

};
