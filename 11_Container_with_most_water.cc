class Solution {
public:

    int MaxMonotonicArea(std::vector<int> &height){
        std::vector < pair<int,int> > monotonic_stack;
        int res = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0)
                monotonic_stack.push_back(make_pair(height[i], i));
            else{
                std::vector< pair<int,int> >::iterator low = std::lower_bound(monotonic_stack.begin(), monotonic_stack.end(), make_pair(height[i], 0));
                if(low - monotonic_stack.begin() < monotonic_stack.size()){
                    int pos = low -> second;
                    res = std::max(res, height[i] * (i - pos));
                }
                if(height[i] > monotonic_stack.back().first)
                    monotonic_stack.push_back(make_pair(height[i], i));
            }
        }
        return res;
    }
    int maxArea(vector<int>& height) {
        int res = MaxMonotonicArea(height);
        std::reverse(height.begin(), height.end());
        return std::max(res, MaxMonotonicArea(height));

    }
};
