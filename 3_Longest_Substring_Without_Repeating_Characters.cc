class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> character_count;
        int start = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(character_count.find(s[i]) == character_count.end())
                character_count[s[i]] = 1;
            else
                character_count[s[i]] += 1;
            while(character_count[s[i]] > 1){
                character_count[s[start]]--;
                start++;
            }
            res = std::max(res, i - start + 1);
        }
        return res;
    }
};
