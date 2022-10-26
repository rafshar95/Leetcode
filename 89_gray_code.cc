class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1)
            return {0, 1};
        std::vector<int> part1 = grayCode(n - 1);
        std::vector<int> part2 = part1;
        std::reverse(part2.begin(), part2.end());
        for(int i = 0; i < part2.size(); i++){
            part2[i] += (1 << (n - 1));
            part1.push_back(part2[i]);
        }
        return part1;
    }
};
