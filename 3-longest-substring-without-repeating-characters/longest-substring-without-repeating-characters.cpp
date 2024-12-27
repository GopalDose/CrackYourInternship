class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxi = 0;  // Initialize maximum length to 0
        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            
            // If there is a duplicate, move the left pointer
            while (mp[s[i]] > 1) {
                mp[s[left]]--;
                left++;
            }
            
            // Calculate the maximum length of the substring
            maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};
