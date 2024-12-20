class Solution {
public:
    bool solve(vector<int>& nums, int n, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target+1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int t = 1; t <= target; t++) {
                bool include = 0;
                if (t - nums[index] >= 0)
                    include = dp[index + 1][t - nums[index]];
                bool exclude = dp[index + 1][t];

                dp[index][t] = (include || exclude);
            }
        }
        return dp[0][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        if (sum % 2)
            return 0;
        return solve(nums, n, sum / 2);
    }
};