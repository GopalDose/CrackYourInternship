class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        for (auto i : nums) {
            mp[i]++;
            sum += i;
        }

        int res = INT_MIN;
        for (auto i : nums) {
            int newSum = sum - i;
            mp[i]--;
            if ( newSum%2 == 0 && mp.find(newSum / 2) != mp.end() && mp[newSum / 2] > 0)
                res = max(res, i);
            mp[i]++;
        }
        return res;
    }
};