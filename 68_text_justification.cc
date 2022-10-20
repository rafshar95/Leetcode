class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::vector<int>> words_index;
        int capacity = maxWidth;
        for(int i = 0; i < words.size(); i++){
            if(capacity == maxWidth){
                std::vector<int> tmp;
                tmp.push_back(i);
                words_index.push_back(tmp);
                capacity -= words[i].size();
            }
            else{
                if(capacity > words[i].size()){
                    capacity -= words[i].size() + 1;
                    words_index.back().push_back(i);
                }
                else{
                    capacity = maxWidth - words[i].size();
                    std::vector<int> tmp;
                    tmp.push_back(i);
                    words_index.push_back(tmp);
                }
            }
        }
        std::vector<std::string> res;
        for(int i = 0; i < words_index.size(); i++){
            std::string tmp = "";
            if(i == words_index.size() - 1){
                for(int j = 0; j < words_index[i].size(); j++){
                    if(j != 0)
                        tmp += " ";
                    tmp += words[words_index[i][j]];
                }
                std::string tmp2(maxWidth - tmp.size(), ' ');
                tmp += tmp2;
            }
            else{
                if(words_index[i].size() == 1){
                    tmp = words[words_index[i][0]];
                    std::string tmp2(maxWidth - tmp.size(), ' ');
                    tmp += tmp2;
                }
                else{
                    int capacity = maxWidth;
                    for(int j = 0; j < words_index[i].size(); j++)
                        capacity -= words[words_index[i][j]].size();
                    int division = words_index[i].size() - 1;
                    for(int j = 0; j < words_index[i].size(); j++){
                        tmp += words[words_index[i][j]];
                        if(j + 1 != words_index[i].size()){
                            if(j < capacity % division){
                                std::string tmp2(capacity / division + 1, ' ');
                                tmp += tmp2;
                            }
                            else{
                                std::string tmp2(capacity / division, ' ');
                                tmp += tmp2;
                            }
                        }
                    }
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
