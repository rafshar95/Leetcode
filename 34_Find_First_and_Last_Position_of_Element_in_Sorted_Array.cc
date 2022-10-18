class Solution {
public:
    int LowerBound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        if(target > nums.back())
            return nums.size();
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || target < nums[0] || target > nums.back())
            return {-1 , - 1};
        int first = LowerBound(nums, target);
        int last = LowerBound(nums, target + 1);
        if(nums[first] != target)
            return {-1, -1};
        return {first, last - 1};
    }
};
