class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        digits.back()++;
        for(int i = digits.size() - 1; i >= 0; i --){
            if(digits[i] <= 9)
                return digits;
            else{
                digits[i] %= 10;
                if(i == 0){
                    std::vector<int> res(digits.size() + 1, 0);
                    res[0] = 1;
                    return res;
                }
                else{
                    digits[i - 1]++;
                }
            }
        }
        return digits;
    }
};
