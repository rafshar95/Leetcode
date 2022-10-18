class Solution {
public:
    bool isValid(string s) {
        int open_parantheses_count = 0;
        int open_brackets_count = 0;
        int open_braces_count = 0;
        vector<char> letters;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                letters.push_back(s[i]);
            else if(!letters.size())
                return false;
            if(s[i] == ')'){
                if(letters.back() != '(')
                    return false;
                letters.pop_back();
            }
            if(s[i] == ']'){
                if(letters.back() != '[')
                    return false;
                letters.pop_back();
            }
            if(s[i] == '}'){
                if(letters.back() != '{')
                    return false;
                letters.pop_back();
            }
        }
        return (letters.size() == 0);
    }
};
