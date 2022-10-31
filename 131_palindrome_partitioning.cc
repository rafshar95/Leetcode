class Solution {
public:
    std::vector<std::string> Split(std::string& s, int bit_mask_partition){
        int last_pos = 0;
        std::vector<std::string> result;
        bit_mask_partition |= (1 << (s.size() - 1));
        for(int i = 0; (1 << i) <= bit_mask_partition; i++)
            if((1 << i) & bit_mask_partition){
                result.push_back(s.substr(last_pos, i - last_pos + 1));
                last_pos = i + 1;
            }
        return result;
    }
    bool IsPalindrome(std::vector<std::string>& partition){
        for(int i = 0; i < partition.size(); i++)
            for(int j = 0; j < partition[i].size(); j++)
                if(partition[i][j] != partition[i][partition[i].size() - j - 1])
                    return false;
        return true;
    }
    vector<vector<string>> partition(string s) {
        if(s.size() == 1)
            return {{s}};
        int number_of_possible_partitions = s.size() - 1;
        std::vector<std::vector<std::string>> results;
        for(int i = 0; i < ( 1 << number_of_possible_partitions); i++){
            std::vector<std::string> splitted_string = Split(s, i);
            if(IsPalindrome(splitted_string))
                results.push_back(splitted_string);
        }
        return results;
    }
};
