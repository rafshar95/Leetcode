class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        for(int i = m; i <= m + n - 2; i++){
            res *= i;
            res /= i - (m - 1);
        }
        return res;
    }
};
