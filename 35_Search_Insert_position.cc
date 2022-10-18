class Solution {
public:
    int binary_search(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
       if(target > nums.back())
           return nums.size();
        if(target == nums.back())
            return nums.size() - 1;
        if(target < nums[0])
            return 0;
        int pos = binary_search(nums, target);
        if(nums[pos] >= target)
            return pos;
        else
            return pos + 1;

    }
};
