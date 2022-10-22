class Solution {
public:
    int MapLetterToInt(char c){
        if(c >= 'a' && c <= 'z')
            return c - 'a';
        else
            return c - 'A' + 26;
    }
    string minWindow(string s, string t) {
        std::vector<int> window_letter_count(52, 0);
        std::vector<int> necessary_letter_count(52, 0);
        for(int i = 0; i < t.size(); i++)
            necessary_letter_count[MapLetterToInt(t[i])]++;
        int number_missing_letter_requirements = 0;
        for(int i = 0; i < 52; i++)
            if(necessary_letter_count[i] > 0)
                number_missing_letter_requirements++;
        std::string res = "";
        for(int i = 0, j = 0; i < s.size(); i++){
            while(number_missing_letter_requirements && j < s.size()){
                window_letter_count[MapLetterToInt(s[j])]++;
                if(window_letter_count[MapLetterToInt(s[j])] == necessary_letter_count[MapLetterToInt(s[j])])
                    number_missing_letter_requirements--;
                j++;
            }
            if(!number_missing_letter_requirements){
                if(res.size() == 0 || res.size() > j - i)
                    res = s.substr(i, j - i);
                window_letter_count[MapLetterToInt(s[i])]--;
                if(window_letter_count[MapLetterToInt(s[i])] < necessary_letter_count[MapLetterToInt(s[i])])
                    number_missing_letter_requirements++;
            }
            else
                break;
        }
        return res;
    }
};
