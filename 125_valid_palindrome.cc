class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                res += s[i];
            if(s[i] >= '0' && s[i] <= '9')
                res += s[i];
            if(s[i] >= 'A' && s[i] <= 'Z')
                res += char(s[i] - 'A' + 'a');
        }
        for(int i = 0; i < res.size(); i++)
            if(res[i] != res[res.size() - i - 1])
                return false;
        return true;
    }
};
