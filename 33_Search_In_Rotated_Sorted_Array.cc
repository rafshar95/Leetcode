class Solution {
public:
    int GetFirstNumberLessThanLast(vector<int>& nums){
        int l = 0;
        int r = nums.size() - 1;
        if(nums[0] < nums.back())
            return l;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums.back())
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int BinarySearch(vector<int>& nums, int target, int l, int r){
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        if(nums[l] == target)
            return l;
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = GetFirstNumberLessThanLast(nums);
        std::cout << l << std::endl;
        int val = BinarySearch(nums, target, l, nums.size() - 1);
        if(val != -1)
            return val;
        if(l != 0)
            val = BinarySearch(nums, target, 0, l - 1);
        return val;
    }
};
