class Solution {
public:
    string convert(string s, int numRows) {
        string res = s;
        int pos = 0;
        if(numRows == 1)
            return s;
        for(int i = 1; i <= numRows; i++){
            int cur = i - 1;
            if(i == 1 || i == numRows){
                while(cur < s.size()){
                    res[pos++] = s[cur];
                    cur += (numRows * 2 - 2);
                }
            }
            else{
                while(cur < s.size()){
                    res[pos++] = s[cur];
                    if (cur + (numRows - i) * 2 < s.size())
                        res[pos++] = s[cur + (numRows - i) * 2];
                    cur += (numRows * 2 - 2);
                }
            }
        }
        return res;
    }
};
