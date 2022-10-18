class Solution {
public:

    std::vector <int> max_range_dp_;
    int FindMaxDp(int node, int left, int right, int min_pos, int max_pos) {
        if(left > right)
            return 0;
        if(min_pos <= left && right <= max_pos)
            return max_range_dp_[node];
        if(max_pos < left || min_pos > right)
            return 0;
        int mid = (left + right) / 2;
        return std::max(FindMaxDp((node << 1) + 1, left, mid, min_pos, max_pos), FindMaxDp((node << 1) + 2, mid + 1, right, min_pos, max_pos));
    }
    void UpdateDp(int node, int left, int right, int pos, int value) {
        if (pos < left || pos > right)
            return;
        max_range_dp_[node] = std::max(max_range_dp_[node], value);
        if(left == right)
            return;
        int mid = (left + right) / 2;
        UpdateDp((node << 1) + 1, left, mid, pos, value);
        UpdateDp((node << 1) + 2, mid + 1, right, pos, value);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int max_num = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            max_num = std::max(nums[i], max_num);
        for(int i = 0; i < max_num * 4; i++)
            max_range_dp_.push_back(0);
        for(int i = 0; i < nums.size(); i++) {
            int max_dp = FindMaxDp(0, 1, max_num, nums[i] - k, nums[i] - 1);
            result = std::max(result, max_dp + 1);
            UpdateDp(0, 1, max_num, nums[i], max_dp + 1);
        }
        return result;
    }
};
