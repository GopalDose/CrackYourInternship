static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;

        int count = 0, j = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++)
            count += nums[i];

        for (int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i - 1];
            if (i == count - 1)
                ans = min(ans, count - nums[i]);
            if (i >= count)
                ans = min(ans, count - nums[i] + nums[i - count]);
        }

        for (int i = n; i < n + count; i++) {
            int a = i - n;
            nums[a] = nums[a] + nums[n - 1];
            ans = min(ans, count - nums[a] + nums[i - count]);
        }
        return ans;
    }
};