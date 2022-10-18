class Solution {
public:
    int longestValidParentheses(string s) {
        int open_minus_closed_paranthesis_cnt = 0;
        int ans = 0;
        std::vector<std::pair<int, int> > monotonic_value;
        monotonic_value.push_back(std::make_pair(0, - 1));
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                open_minus_closed_paranthesis_cnt++;
            }
            if(s[i] == ')')
                open_minus_closed_paranthesis_cnt--;
            while(!monotonic_value.empty() && monotonic_value.back().first > open_minus_closed_paranthesis_cnt){
                monotonic_value.pop_back();
            }
            if(!monotonic_value.empty()){
                int val = monotonic_value.back().first;
                int idx = monotonic_value.back().second;
                if(val == open_minus_closed_paranthesis_cnt){
                    ans = std::max(ans, i - idx);
                }
                else{
                    monotonic_value.push_back(std::make_pair(open_minus_closed_paranthesis_cnt, i));
                }
            }
            else{
                monotonic_value.push_back(std::make_pair(open_minus_closed_paranthesis_cnt, i));
            }
        }
        return ans;
    }

};
