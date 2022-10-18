class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::map <long long, int> mp_last;
        for(int i = 0; i < nums.size(); i++)
            mp_last[nums[i]] = i;
        std::vector <int> quadruplet;
        std::vector<std::vector<int>> quadruplets;
        std::map <std::vector<int>, bool> unique_quadruplets;
        long long target_ll = target;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                for(int l = j + 1; l < nums.size(); l++){
                    if(mp_last.find(target_ll - nums[i] - nums[j] - nums[l]) != mp_last.end() && mp_last[target_ll - nums[i] - nums[j] - nums[l]] > l){
                        quadruplet = {nums[i], nums[j], nums[l], nums[mp_last[target_ll - nums[i] - nums[j] - nums[l]]]};
                        unique_quadruplets[quadruplet] = true;
                    }
                }
        for(std::map <std::vector<int>, bool>::iterator it = unique_quadruplets.begin(); it != unique_quadruplets.end(); it++){
            quadruplets.push_back(it -> first);
        }
        return quadruplets;
    }
};
