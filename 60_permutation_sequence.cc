class Solution {
public:
    string getPermutation(int n, int k) {
        std::vector<int> factorials;
        factorials.push_back(0);
        factorials.push_back(1);
        for(int i = 2; i <= n; i++)
            factorials.push_back(factorials.back() * i);
        std::vector<bool> number_used(10);
        string res = "";
        for(int i = 1; i <= n; i++){
            int number_order = 1;
            for(int j = n - i + 1; j >= 1; j--){
                if(k > (j - 1) * factorials[n - i]){
                    number_order = j;
                    k -= (j - 1) * factorials[n - i];
                    break;
                }
            }
            for(int i = 1; i <= n; i++){
                if(!number_used[i] && number_order)
                    number_order--;
                if(!number_order){
                    number_used[i] = true;
                    res += char(i + '0');
                    break;
                }
            }
        }
        return res;
    }
};
