class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int buy = prices[0];
        int diff = 0;
        int prev = 0;
        for(int i = 1; i<prices.size(); i++){
            if(buy > prices[i]){
                buy = prices[i];
            }
            diff = prices[i] - buy;
            maxi = max(maxi, maxi+diff);
            if(maxi != prev){
                buy = prices[i];
            }
        }
        return maxi;
    }
};