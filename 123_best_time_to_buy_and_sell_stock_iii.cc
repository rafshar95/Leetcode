class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<int> best_profit_prefix(prices.size()), best_profit_suffix(prices.size());
        int best_purchase_price = -1;
        for(int i = 0; i < best_profit_prefix.size(); i++){
            if(i == 0)
                best_purchase_price = prices[i];
            if(i)
                best_profit_prefix[i] = best_profit_prefix[i - 1];
            best_profit_prefix[i] = std::max(best_profit_prefix[i], prices[i] - best_purchase_price);
            best_purchase_price = std::min(best_purchase_price, prices[i]);
        }
        int best_sale_price = -1;
        for(int i = prices.size() - 1; i >= 0; i--){
            if(i == prices.size() - 1)
                best_sale_price = prices[i];
            else
                best_profit_suffix[i] = best_profit_suffix[i + 1];
            best_profit_suffix[i] = std::max(best_profit_suffix[i], best_sale_price - prices[i]);
            best_sale_price = std::max(best_sale_price, prices[i]);
        }
        int best_total_profit = 0;
        for(int i = 0; i < prices.size(); i++)
            best_total_profit = std::max(best_total_profit, best_profit_suffix[i] + best_profit_prefix[i]);

        return best_total_profit;
    }
};
