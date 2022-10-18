class Solution {
public:
    void GenerateAllParantheses(int parantheses_count, int index, int open_paranthesis_count, int open_minus_closed_count, string parantheses, vector<string> &res){
        if(index == 2 * parantheses_count){
            res.push_back(parantheses);
            return;
        }
        if(open_paranthesis_count < parantheses_count){
            GenerateAllParantheses(parantheses_count, index + 1, open_paranthesis_count + 1, open_minus_closed_count + 1, parantheses + '(', res);
        }
        if(open_minus_closed_count > 0){
             GenerateAllParantheses(parantheses_count, index + 1, open_paranthesis_count, open_minus_closed_count - 1, parantheses + ')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        GenerateAllParantheses(n, 0, 0, 0, "", res);
        return res;
    }
};
