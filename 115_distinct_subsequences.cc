class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size())
            return 0;
        std::vector<std::vector<long long>> dp(2, std::vector<long long> (s.size() + 1));
        for(int i = 0; i <= s.size(); i++)
            dp[0][i] = 1;
        for(int i = 0; i < t.size(); i++){
            for(int j = 0; j <= s.size(); j ++){
                dp[(i + 1) % 2][j] = 0;
            }
            for(int j = i; j + t.size() - i - 1 < s.size(); j++){
                if(t[i] == s[j]){
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + dp[(i + 1) % 2][j];
                }
                else
                    dp[(i + 1) % 2][j + 1] = dp[(i + 1) % 2][j];
            }
        }
        return dp[t.size() % 2][s.size()];
    }
};
