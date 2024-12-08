class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        vector<long long> minPre(k, LLONG_MAX);
        long long m = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int temp = i % k;

            if (i >= k) {
                m = max(m, preSum[i] - minPre[temp]);
            }

            minPre[temp] = min(minPre[temp], preSum[i]);
        }

        return m == LLONG_MIN ? 0 : m;
    }
};