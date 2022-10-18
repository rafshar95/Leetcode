class Solution {
public:
    struct VectorIntHashFunction{
        size_t operator()(const std::vector<int> &values) const{
            size_t res = 0;
            std::hash<int> hasher;
            for(auto &value: values){
                res ^= hasher(value) + 0x9e3779b9 + (res << 6) + (res >> 2);
            }
            return res;
        }
    };
    std::vector<int> CountLetters(std::string& str){
        std::vector <int> letters_count(26, 0);
        for(int i = 0; i < str.size(); i++){
            letters_count[str[i] - 'a']++;
        }
        return letters_count;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::vector<int>, std::vector<std::string>, VectorIntHashFunction> anagram_groups;
        for(int i = 0; i< strs.size(); i++){
            std::vector<int> letters_count = CountLetters(strs[i]);
            if(anagram_groups.find(letters_count) == anagram_groups.end()){
                std::vector<std::string> tmp;
                anagram_groups[letters_count] = tmp;
                anagram_groups[letters_count].push_back(strs[i]);
            }
            else
                anagram_groups[letters_count].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> res;
        for(std::unordered_map<std::vector<int>, std::vector<std::string>, VectorIntHashFunction>::iterator it = anagram_groups.begin(); it != anagram_groups.end(); it++){
            res.push_back(it -> second);
        }
        return res;
    }
};
