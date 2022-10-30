class Solution {
public:
    struct Neighbors{
        bool has_smaller_neighbor;
        bool has_larger_neighbor;
        Neighbors(): has_smaller_neighbor(false), has_larger_neighbor(false) {}
        Neighbors(bool has_smaller_neighbor, bool has_larger_neighbor): has_smaller_neighbor(has_smaller_neighbor), has_larger_neighbor(has_larger_neighbor) {}
    };
    void Connect(int val1, int val2, std::unordered_map<int, Neighbors*>& neighbors){
        if(neighbors.find(val2) == neighbors.end())
            return;
        if(val1 > val2)
            std::swap(val1, val2);
        neighbors[val1] -> has_larger_neighbor = true;
        neighbors[val2] -> has_smaller_neighbor = true;
    }
    int Dfs(int val, std::unordered_map<int, Neighbors*>& neighbors, std::unordered_map<int, int>& subtree_count){
        subtree_count[val] = 1;
        if(neighbors[val] -> has_larger_neighbor && subtree_count.find(val + 1) == subtree_count.end())
            subtree_count[val] += Dfs(val + 1, neighbors, subtree_count);
        if(neighbors[val] -> has_smaller_neighbor && subtree_count.find(val - 1) == subtree_count.end())
            subtree_count[val] += Dfs(val - 1, neighbors, subtree_count);
        return subtree_count[val];
    }
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, Neighbors*> neighbors;
        std::unordered_map<int, int> subtree_count;
        for(int i = 0, cnt = 0; i < nums.size(); i++){
            if(neighbors.find(nums[i]) == neighbors.end()){
                neighbors[nums[i]] = new Neighbors();
            }
            Connect(nums[i], nums[i] + 1, neighbors);
            Connect(nums[i], nums[i] - 1, neighbors);
        }
        int maximum_consecutive_sequence = 0;
        std::cout << " 1";
        for(int i = 0; i < nums.size(); i++){
            if(subtree_count.find(nums[i]) == subtree_count.end()){
                maximum_consecutive_sequence = std::max(maximum_consecutive_sequence, Dfs(nums[i], neighbors, subtree_count));
            }
        }
        return maximum_consecutive_sequence;
    }
};
