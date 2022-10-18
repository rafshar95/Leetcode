class Solution {
public:
    void AddAllCombination(std::vector<string> &res, string digits, int pos, string combination, const std::vector<int> &start_char, const std::vector<int> &num_char){
        if(pos == digits.size()){
            res.push_back(combination);
            return;
        }
        const int kVectorIndex = digits[pos] - '2';
        for(int i = start_char[kVectorIndex]; i < start_char[kVectorIndex] + num_char[kVectorIndex]; i++)
            AddAllCombination(res, digits, pos + 1, combination + char('a' + i), start_char, num_char);
    }
    vector<string> letterCombinations(string digits) {
        std::vector<string> res;
        if(digits.size() == 0)
            return res;
        const std::vector<int> start_char = {0, 3, 6, 9, 12, 15, 19, 22};
        const std::vector<int> num_char = {3, 3, 3, 3, 3, 4, 3, 4};
        AddAllCombination(res, digits, 0, "", start_char, num_char);
        return res;
    }
};
