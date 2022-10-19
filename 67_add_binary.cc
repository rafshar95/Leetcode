class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size())
            std::swap(a, b);
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int res = 0;
        string ans = "";
        for(int i = 0; i < std::max(a.size(), b.size()); i++){
            int sum = 0;
            if(i < a.size())
                sum += a[i] - '0';
            if(i < b.size())
                sum += b[i] - '0';
            sum += res;
            ans += char('0' + sum % 2);
            res = sum / 2;
        }
        if(res > 0)
            ans += '1';
        std::reverse(ans.begin(), ans.end());
        return ans;

    }
};
