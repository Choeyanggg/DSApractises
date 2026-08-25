class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int sell=INT_MIN;
        for(int price: prices){
            buy=min(buy,price);
            sell=max(sell,price-buy);
        }
        return sell;
    }
};