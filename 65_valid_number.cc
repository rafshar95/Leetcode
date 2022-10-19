class Solution {
public:
    bool IsDecimalNumber(string s){
        if(s.size() == 0)
            return false;
        if(s[0] != '-' && s[0] != '+' && s[0] != '.' && (s[0] > '9' || s[0] < '0'))
            return false;
        int dot_count = 0;
        int digit_count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.')
                dot_count++;
            if(i > 0 && s[i] != '.' && (s[i] > '9' || s[i] < '0'))
                return false;
            if(s[i] <= '9' && s[i] >= '0')
                digit_count++;
        }
        if(dot_count > 1 || digit_count == 0)
            return false;
        return true;
    }
    bool IsInteger(string s){
        if(s.size() == 0)
            return false;
        if(s[0] != '+' && s[0] != '-' && (s[0] > '9' || s[0] < '0'))
            return false;
        int digit_count = 0;
        for(int i = 0; i < s.size(); i++){
            if(i > 0 && (s[i] > '9' || s[i] < '0'))
                return false;
            if(s[i] <= '9' && s[i] >= '0')
                digit_count++;
        }
        if(!digit_count)
            return false;
        if(s.size() == 1 && (s[0] == '+' || s[0] == '-'))
            return false;
        return true;
    }

    bool isNumber(string s) {
        if(IsDecimalNumber(s) || IsInteger(s))
            return true;
        if(s.size() <= 2)
            return false;
        for(int i = 1; i < s.size() - 1; i++){
            if(s[i] == 'e' || s[i] == 'E'){
                std::string s1 = s.substr(0, i);
                std::string s2 = s.substr(i + 1, s.size() - i - 1);
                if((IsDecimalNumber(s1) && IsInteger(s2)) || (IsInteger(s1) && IsInteger(s2)))
                   return true;
            }
        }
        return false;
    }
};
