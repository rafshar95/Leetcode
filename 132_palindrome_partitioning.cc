class Solution {
public:
    int minCut(string s) {
        std::vector<int> max_palindrome_odd(s.size()), max_palindrome_even(s.size()), minimum_cut_prefix(s.size(), -1);
        for(int i = 0; i < s.size(); i++){
            max_palindrome_odd[i] = 1;
            for(int j = 1; (i - j) >= 0 && i + j < s.size(); j++){
                if(s[i + j] != s[i - j])
                    break;
                max_palindrome_odd[i] += 2;
            }
        }
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; i - j >= 0 && i + j + 1 < s.size(); j++){
                if(s[i - j] != s[i + j + 1])
                    break;
                max_palindrome_even[i] += 2;
            }
        }
        int mid;
        for(int i = 0; i < s.size(); i++){
            minimum_cut_prefix[i] = i;
            if(i % 2 == 0){
                mid = i / 2;
                if(max_palindrome_odd[mid] >= i + 1)
                    minimum_cut_prefix[i] = 0;
            }
            if(i % 2 == 1){
                mid = i / 2;
                if(max_palindrome_even[mid] >= i + 1)
                    minimum_cut_prefix[i] = 0;
            }
            for(int j = 0; j < i; j++){
                if((i - j) % 2 == 0){
                    mid = (i + j) / 2;
                    if(max_palindrome_even[mid] >= (i - j))
                        minimum_cut_prefix[i] = std::min(minimum_cut_prefix[i], minimum_cut_prefix[j] + 1);
                }
                else{
                    mid = (i + j + 1) / 2;
                    if(max_palindrome_odd[mid] >= (i - j))
                       minimum_cut_prefix[i] = std::min( minimum_cut_prefix[i], minimum_cut_prefix[j] + 1);
                }
            }
        }
        return minimum_cut_prefix[s.size() - 1];
    }
};
