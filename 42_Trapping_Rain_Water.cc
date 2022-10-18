class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size () <= 2)
            return 0;
        std::vector<int> max_left(height.size(), 0);
        std::vector<int> max_right(height.size(), 0);
        for(int i = 1; i < height.size(); i++){
            max_left[i] = std::max(max_left[i - 1], height[i - 1]);
        }
        for(int i = height.size() - 2; i >= 0 ; i--){
            max_right[i] = std::max(max_right[i + 1], height[i + 1]);
        }
        int res = 0;
        for(int i = 1; i < height.size() - 1; i ++)
            res += (height[i] < std::min(max_left[i], max_right[i])) ? (std::min(max_left[i], max_right[i]) - height[i]) : 0;
        return res;
    }
};
