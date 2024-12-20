class Solution {
public:
    const int mod = (int)pow(10, 9) + 7;
    int solve(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int index = 1; index <= n; index++) {
            for (int j = 1; j <= target; j++) {
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (j - i >= 0)  // Corrected condition
                        ans = (ans % mod + (dp[index - 1][j - i]) % mod) % mod;
                }
                dp[index][j] = ans;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};
