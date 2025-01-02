class Solution {
public:
    bool isVowel(const string& w) {
        int n = w.length() - 1;
        return (w[0] == 'a' || w[0] == 'e' || w[0] == 'i' || w[0] == 'o' || w[0] == 'u') &&
               (w[n] == 'a' || w[n] == 'e' || w[n] == 'i' || w[n] == 'o' || w[n] == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n, 0);

        // Build the prefix sum array
        for (int i = 0; i < n; i++) {
            prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + (isVowel(words[i]) ? 1 : 0);
        }

        vector<int> results;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            int count = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
            results.push_back(count);
        }

        return results;
    }
};
