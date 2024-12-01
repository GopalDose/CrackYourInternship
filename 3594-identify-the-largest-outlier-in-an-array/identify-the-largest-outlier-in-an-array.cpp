class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            sum += num;
            freq[num]++;
        }

        int res = INT_MIN;

        for (int num : nums) {
            int newSum = sum - num;
            if (newSum % 2 == 0) {
                int target = newSum / 2;
                if ((target != num && freq.count(target)) ||
                    (target == num && freq[num] > 1)) {
                    res = max(res, num);
                }
            }
        }

        return res == INT_MIN ? -1 : res;
    }
};
