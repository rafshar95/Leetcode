class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;
        int sign = (x > 0) ? 1 : -1;
        x = abs(x);
        int res = 0;
        while(x > 0){
            if(res > INT_MAX / 10)
                return 0;
            res *= 10;
            if ( res > INT_MAX - (x % 10))
                return 0;
            res += (x % 10);
            x /= 10;
        }
        return res * sign;
    }
};
