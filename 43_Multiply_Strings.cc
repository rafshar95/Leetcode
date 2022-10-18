class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        std::vector<std::string> numbers(num2.size(), "");
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for(int i = 0; i < num2.size(); i++){
            numbers[i].assign(i, '0');
            int residual = 0;
            for(int j = 0; j < num1.size(); j++){
                int mod = ((num1[j] -'0') * (num2[i] - '0') + residual)  % 10;
                residual = ((num1[j] -'0') * (num2[i] - '0') + residual) / 10;
                numbers[i] += char ('0' + mod);
            }
            while(residual > 0){
                numbers[i] += char('0' + (residual % 10));
                residual /= 10;
            }
        }
        int residual = 0;
        int pos = 0;
        std::string res = "";
        bool finish_sum = false;
        while(!finish_sum){
            int sum_i = 0;
            finish_sum = true;
            if(residual > 0){
                sum_i += residual;
                finish_sum = false;
            }
            for(int i = 0; i < num2.size(); i++)
                if(pos < numbers[i].size()){
                    finish_sum = false;
                    sum_i += numbers[i][pos] - '0';
                }
            if(!finish_sum){
                res += char('0' + sum_i % 10);
                residual = sum_i / 10;
            }
            pos++;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
