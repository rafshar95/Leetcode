class Solution {
public:
    std::vector<int> number_of_trees;
    int numTrees(int n) {
        int res = 0;
        if(number_of_trees.size() > n)
            return number_of_trees[n];
        if(n <= 1){
            number_of_trees.push_back(1);
            return 1;
        }
        for(int i = 1; i <= n; i++){
            int root = i;
            res += numTrees(i - 1) * numTrees(n - i);
        }
        number_of_trees.push_back(res);
        return res;
    }
};
