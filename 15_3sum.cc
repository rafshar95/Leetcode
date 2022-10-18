class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::unordered_map <int, int> mp_last;
        for(int i = 0; i < nums.size(); i++)
            mp_last[nums[i]] = i;
        std::vector< std::vector<int> > res;
        std::set<std::vector<int> > triplets;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(mp_last.find(-nums[i] - nums[j]) != mp_last.end() && mp_last[-nums[i] - nums[j]] > j){
                    triplets.insert({nums[i], nums[j], -nums[i] - nums[j]});
                }
            }
        }
        for(std::set<std::vector<int> >::iterator it = triplets.begin(); it !=triplets.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
};
