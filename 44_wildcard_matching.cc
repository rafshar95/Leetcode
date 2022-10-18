class Solution {
public:
    static const int kMaxStringSize = 2000 + 1;
    bool dp[kMaxStringSize][kMaxStringSize];
    bool dp_star[kMaxStringSize][kMaxStringSize];
    bool isMatch(string s, string p) {
        dp[0][0] = true;
        for(int j = 0; j < s.size(); j++)
            dp_star[0][j + 1] = true;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == '*')
                dp[i + 1][0] = dp[i][0];
            for(int j = 0; j < s.size(); j++){
                if(p[i] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                else if(p[i] != '*'){
                    if(p[i] == s[j])
                        dp[i + 1][j + 1] = dp[i][j];
                }
                else{
                    dp[i + 1][j + 1] = dp_star[i][j + 1] | dp[i][j + 1];
                }
                dp_star[i + 1][j + 1] = dp[i + 1][j + 1] | dp_star[i + 1][j];
            }
        }
        return dp[p.size()][s.size()];
    }
};
