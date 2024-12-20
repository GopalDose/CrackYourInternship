class Solution {
public:
    int solve(vector<int>& arr, int amount,  vector<int> &dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        int mini = INT_MAX;
        int ans = 0;
        if(dp[amount] != -1) return dp[amount];
        for (int i = 0; i < arr.size(); i++) {
            ans = solve(arr, amount - arr[i], dp);
            if (ans != INT_MAX)
                mini = min(mini, ans + 1);
        }
        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans  = solve(coins, amount, dp);
        return  ans!= INT_MAX ? ans : -1;
    }
};