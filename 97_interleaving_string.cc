class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool> (s2.size() + 1));
        dp[0][0] = true;
        for(int i = 0; i <= s1.size(); i++)
            for(int j = 0; j <= s2.size(); j++){
                for(int l = j; l >= 1; l--){
                    if(s2[l - 1] != s3[i + l - 1])
                        break;
                    dp[i][j] = dp[i][j] | dp[i][l - 1];
                }
                for(int l = i; l >= 1; l--){
                    if(s1[l - 1] != s3[j + l - 1])
                        break;
                    dp[i][j] = dp[i][j] | dp[l - 1][j];
                }
            }
        return dp[s1.size()][s2.size()];
    }
};
