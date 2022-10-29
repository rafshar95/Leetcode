class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int purchase_price = -1;
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(purchase_price == -1)
                purchase_price = prices[i];
            if(purchase_price < prices[i]){
                profit += prices[i] - purchase_price;
                purchase_price = prices[i];
            }
            purchase_price = std::min(purchase_price, prices[i]);
        }
        return profit;
    }
};
