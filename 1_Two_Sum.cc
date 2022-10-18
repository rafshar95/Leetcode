class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::map<int, int> mp;
      std::vector<int> res;
      for(int i = 0; i < nums.size(); i++){
        if(mp.find(target - nums[i]) != mp.end()) {
          res = {i, mp[target - nums[i]]};
        }
        mp[nums[i]] = i;
      }
      return res;
    }
};
