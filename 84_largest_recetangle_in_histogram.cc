class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::vector<std::pair<int,int> > increasing_heights;
        std::vector<int> left_index(heights.size());
        std::vector<int> right_index(heights.size());

        for(int i = 0; i < heights.size(); i++){
            while(!increasing_heights.empty() && increasing_heights.back().second >= heights[i])
                increasing_heights.pop_back();
            if(increasing_heights.empty())
                left_index[i] = 0;
            else
                left_index[i] = increasing_heights.back().first + 1;
            increasing_heights.push_back(std::make_pair(i, heights[i]));
        }
        increasing_heights.clear();
        for(int i = heights.size() - 1; i >= 0; i--){
            while(!increasing_heights.empty() && increasing_heights.back().second >= heights[i])
                increasing_heights.pop_back();
            if(increasing_heights.empty())
                right_index[i] = heights.size() - 1;
            else
                right_index[i] = increasing_heights.back().first - 1;
            increasing_heights.push_back(std::make_pair(i, heights[i]));
        }

        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            ans = std::max(ans, heights[i] * (right_index[i] - left_index[i] + 1));
        }
        return ans;
    }
};
