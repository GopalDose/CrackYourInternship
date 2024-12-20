class Solution {
public:
    bool solve(vector<int>& nums, int n, int target) {
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        // Base case: there's always a way to get sum 0 (by selecting no elements)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the dp table
        for (int index = 1; index <= n; index++) {
            for (int t = 1; t <= target; t++) {
                bool include = false;
                if (t - nums[index - 1] >= 0)
                    include = dp[index - 1][t - nums[index - 1]];
                bool exclude = dp[index - 1][t];

                dp[index][t] = include || exclude;
            }
        }
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        // If the total sum is odd, we cannot partition it equally
        if (sum % 2 != 0)
            return false;
        return solve(nums, n, sum / 2);
    }
};
