class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return x;
        long long left = 1, right = 1 << 16;
        long long mid = left;
        while(left < right){
            mid = (left + right + 1) / 2;
            if(mid * mid > x)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
