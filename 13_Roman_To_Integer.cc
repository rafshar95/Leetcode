class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        std::unordered_map<char, int> mp_char = {{'I', 1},
                                                 {'V', 5},
                                                 {'X', 10},
                                                 {'L', 50},
                                                 {'C', 100},
                                                 {'D', 500},
                                                 {'M', 1000}};
        for(int i = 0; i < s.size(); i++){
            if(i == s.size() - 1){
                res += mp_char[s[i]];
                break;
            }
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                res -= mp_char[s[i]];
                res += mp_char[s[i+1]];
                i++;
                continue;
            }
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                res -= mp_char[s[i]];
                res += mp_char[s[i+1]];
                i++;
                continue;
            }
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                res -= mp_char[s[i]];
                res += mp_char[s[i+1]];
                i++;
                continue;
            }
            else
                res += mp_char[s[i]];
        }
        return res;
    }
};
