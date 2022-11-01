class Solution {
public:
    int candy(vector<int>& ratings) {
        std::vector<int> dp_left(ratings.size(), 1);
        std::vector<int> dp_right(ratings.size(), 1);
        for(int i = 0; i < ratings.size(); i++)
            if(i && ratings[i] > ratings[i - 1])
                dp_left[i] = dp_left[i - 1] + 1;
        for(int i = ratings.size() - 1; i >= 0; i--)
            if(i != ratings.size() - 1 && ratings[i] > ratings[i + 1])
                dp_right[i] =dp_right[i + 1] + 1;
        int sum_candies = 0;
        for(int i = 0; i < ratings.size(); i++)
            sum_candies += std::max(dp_right[i], dp_left[i]);
        return sum_candies;
    }
};
