class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_string_size = -1;
        for(int i= 0; i < strs.size() ; i++){
            if(min_string_size == -1 || min_string_size > strs[i].size())
                min_string_size = strs[i].size();
        }
        for(int i = 0; i < min_string_size; i++){
            for(int j = 1; j < strs.size(); j++)
                if(strs[0][i] != strs[j][i]){
                    return strs[0].substr(0, i);
                }
        }
        return strs[0].substr(0, min_string_size);
    }
};
