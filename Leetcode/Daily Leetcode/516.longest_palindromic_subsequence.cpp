class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: single characters are palindromes of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Build the DP table
        for (int i = n - 1; i >= 0; --i) { // Start from THE END
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1]; // Full string
    }
};