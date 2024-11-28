class Solution {
public:
    void solve(vector<int>& prices, int i, int& mini, int& maxi) {
        if (i == prices.size()) {
            return;
        }

        if (prices[i] < mini)
            mini = prices[i];
        int pro = prices[i] - mini;
        if (pro > maxi)
            maxi = pro;
        solve(prices, i+1, mini, maxi);
    }
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        solve(prices, 0, mini, maxi);
        return maxi;
    }
};