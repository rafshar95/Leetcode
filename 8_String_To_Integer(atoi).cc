class Solution {
public:
    int myAtoi(string s) {
        long long val = 0;
        int sign = 0;
        bool non_space = false;
        for(int i = 0; i < s.size(); i++) {
            if ((s[i]> '9' || s[i] < '0') && (i>0 && s[i - 1] <= '9' && s[i - 1] >= '0'))
                break;
            if ((s[i]> '9' || s[i] < '0') &&  s[i] != '+' && s[i] != '-' && s[i] != ' ')
                break;
            if(s[i] == ' ' && non_space == true)
                break;
            if(s[i] != ' ')
                non_space = true;
            if((s[i] == '-' || s[i] == '+') && sign != 0)
                break;
            if(s[i] == '+')
                sign = 1;
            if(s[i] == '-')
                sign = -1;
            if(s[i] <= '9' && s[i] >= '0'){
                val = val * 10 + (s[i] - '0');
                if(val > INT_MAX)
                    val = 1ll + INT_MAX;
            }
        }
        if(sign >= 0) {
            if(val <= INT_MAX)
                return val;
            return INT_MAX;
        }
        val *= sign;
        if(val >= INT_MIN)
            return val;
        return INT_MIN;
    }
};
