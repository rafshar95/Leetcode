class Solution {
public:
    bool ValidInteger(std::string& s){
        if(s.size() > 3)
            return false;
        for(int i = 0; i < s.size(); i++)
            if(s[i] < '0' || s[i] > '9')
                return false;
        if(s.size() > 1 && s[0] == '0')
            return false;
        if(s.size() == 3 && s[0] > '2')
            return false;
        if(s.size() == 3 && s[0] == '2' && s[1] > '5')
            return false;
        if(s.size() == 3 && s[0] == '2' && s[1] == '5' && s[2] > '5')
            return false;
        return true;
    }
    void FindAllValidIP(std::string& s, std::string cur, int integer_count, int pos, std::vector<std::string>& results){
        if(integer_count == 4){
            if(pos == s.size())
                results.push_back(cur);
            return;
        }
        for(int i = pos; i <= s.size() - 1; i++){
            std::string tmp = s.substr(pos, i - pos + 1);
            if(ValidInteger(tmp)){
                if(cur == ""){
                     FindAllValidIP(s, tmp, integer_count + 1, i + 1, results);
                }
                else
                    FindAllValidIP(s, cur + "." + tmp, integer_count + 1, i + 1, results);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        std::vector<std::string> results;
        FindAllValidIP(s, "", 0, 0, results);
        return results;
    }
};
