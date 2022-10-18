class Solution {
public:
    string longestPalindrome(string s) {
        int max_size = 1;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 1; i-j >= 0 && i+j < s.size(); j++){
                if(s[i-j] != s[i+j])
                    break;
                if(max_size < 2 * j + 1) {
                    max_size = 2 * j + 1;
                    start = i - j;
                }
            }
            for(int j = 1; i-j+1 >= 0 && i+j < s.size(); j++){
                if(s[i-j+1] != s[i+j])
                    break;
                if(max_size < 2 * j + 1) {
                    max_size = 2 * j;
                    start = i - j + 1;
                }
            }
        }
        return s.substr(start, max_size);
    }
};
