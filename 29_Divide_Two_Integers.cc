class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if(divisor == INT_MIN){
            if(dividend == INT_MIN)
                return 1;
            return 0;
        }
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return -dividend;
        bool sign = 1;
        int plus_one = 0;
        if(divisor < 0){
            divisor = -divisor;
            sign^=1;
        }
        if(dividend < 0){
            if(dividend != INT_MIN)
                dividend = -dividend;
            else{
                dividend = INT_MAX;
                plus_one = 1;
            }
            sign^=1;
        }
        std::vector<int> powers;
        powers.push_back(divisor);
        while(powers.back() < (1 << 30))
            powers.push_back(powers.back() + powers.back());
        int res = 0;
        for(int i = powers.size() - 1; i > -1; i--){
            while (powers[i] <= dividend){
                dividend -= powers[i];
                res += (1 << i);
            }
        }
        dividend += plus_one;
        while(dividend >= powers[0]){
            res +=1;
            dividend -= powers[0];
        }

        if(sign == 0)
            return -res;
        return res;

    }
};
