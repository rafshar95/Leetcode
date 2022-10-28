class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        std::vector<int> prev = triangle[0];
        std::vector<int> cur = prev;
        for(int i = 1; i < triangle.size(); i++){
            cur = triangle[i];
            for(int j = 0; j < cur.size(); j++){
                if(j == 0){
                    cur[j] += prev[j];
                }
                else if(j == cur.size() - 1){
                    cur[j] += prev[j - 1];
                }
                else{
                    cur[j] += std::min(prev[j - 1], prev[j]);
                }
            }
            prev = cur;
        }
        return *std::min_element(cur.begin(), cur.end());
    }
};
