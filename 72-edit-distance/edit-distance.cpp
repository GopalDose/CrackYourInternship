class Solution {
public:
    int solve(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, 0));
        
        // Base cases
        for (int i = 0; i <= text1.length(); i++) {
            dp[i][text2.length()] = text1.length() - i;
        }
        for (int j = 0; j <= text2.length(); j++) {
            dp[text1.length()][j] = text2.length() - j;
        }
        
        // Filling the DP table
        for (int i = text1.length() - 1; i >= 0; i--) {
            for (int j = text2.length() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min({dp[i + 1][j], // Deletion
                                        dp[i][j + 1], // Insertion
                                        dp[i + 1][j + 1]}); // Substitution
                }
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return solve(word1, word2); // Directly return the calculated edit distance
    }
};
