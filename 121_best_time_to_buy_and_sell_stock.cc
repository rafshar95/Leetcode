class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int kMinPrice = 10000;
        int min_price = kMinPrice;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            min_price = std::min(prices[i], min_price);
            ans = std::max(ans, prices[i] - min_price);
        }
        return ans;
    }
};
