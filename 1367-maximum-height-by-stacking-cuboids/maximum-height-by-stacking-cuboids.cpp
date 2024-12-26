class Solution {
public:
    int solve(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> dp(n, 0);

        // Base case: each cuboid alone can be a stack
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2]; // The height of the cuboid
        }

        // Build the solution bottom-up
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (cuboids[j][0] <= cuboids[i][0] &&
                    cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }

        // The maximum value in dp array is the result
        return *max_element(dp.begin(), dp.end());
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort dimensions of each cuboid to ensure width ≤ depth ≤ height
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        // Sort cuboids by dimensions to ensure a valid stacking order
        sort(cuboids.begin(), cuboids.end());

        // Solve the problem using dynamic programming
        return solve(cuboids);
    }
};
