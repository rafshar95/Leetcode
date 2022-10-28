class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        std::vector<int> prev = {1};
        std::vector<int> cur;
        for(int i = 1; i <= rowIndex; i++){
            cur.clear();
            cur.push_back(1);
            for(int j = 0; j < int(prev.size() - 1); j++)
                cur.push_back(prev[j] + prev[j + 1]);
            cur.push_back(1);
            prev = cur;
        }
        return cur;
    }
};
