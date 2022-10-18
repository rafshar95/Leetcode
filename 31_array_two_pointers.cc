class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                int first = i + 1;
                int last = nums.size() - 1;
                while(last > first){
                    std::swap(nums[first], nums[last]);
                    first++;
                    last--;
                }
                for(int j = i + 1; j < nums.size(); j++)
                    if(nums[j] > nums[i]){
                        std::swap(nums[i], nums[j]);
                        return;
                    }
            }
        }
        int first = 0;
        int last = nums.size() - 1;
        while(last > first){
            std::swap(nums[first], nums[last]);
            first++;
            last--;
        }

    }
};
