class Solution {
public:
    int climbStairs(int n) {
       if(n <= 2)
           return n;
        std::vector<int> ans = {1, 2};
        for(int i = 3; i <= n; i++)
            ans.push_back(ans[i - 2] + ans[i - 3]);
        return ans.back();
    }
};
