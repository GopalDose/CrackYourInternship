class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy =prices[0];
        int p = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i] < buy)
                buy = prices[i];
            p = max(p, prices[i] - buy);
        }

        return p;
    }
};