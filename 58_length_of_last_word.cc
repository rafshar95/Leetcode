class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool new_word = true;
        for(int i = 0; i < s.size(); i++){
            if(!new_word && s[i] != ' '){
                length++;
            }
            if(new_word && s[i] != ' '){
                new_word = false;
                length = 1;
            }
            if(s[i] == ' '){
                new_word = true;
            }
        }
        return length;
    }
};
