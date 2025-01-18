class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int ans = 0;
        for (int st : set) {
            if (set.find(st - 1) == set.end()) {
                int curr = st;
                int seq = 1;
                while (set.find(curr + 1) != set.end()) {
                    curr++;
                    seq++;
                }
                ans =max(ans, seq);
            }
        }
        return ans;
    }
};