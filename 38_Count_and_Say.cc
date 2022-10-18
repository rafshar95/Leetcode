class Solution {
public:
    string countAndSay(int n) {
        std::string res = "1";
        if(n == 1)
            return res;
        for(int i = 2; i <= n; i++){
            int cnt = 0;
            std::string next_res = "";
            for(int j = 0; j < res.size(); j++){
                if(j == 0 || res[j] != res[j - 1])
                    cnt = 1;
                else
                    cnt++;
                if(j == res.size() - 1 || res[j+1] != res[j]){
                    next_res += std::to_string(cnt);
                    next_res += res[j];
                }
            }
            res = next_res;
        }
        return res;
    }
};
