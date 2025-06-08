class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // use a 3D DP array where dp[i][j][0] is the score of player1 and dp[i][j][1] is the score of player
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        // Base case: when i == j, the only choice for player1
        for (int i = 0; i < n; i++) {
            dp[i][i][0] = nums[i];
            dp[i][i][1] = 0;
        }

        // Fill DP table for all subarray lengths > 1
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                // Option 1: player1 picks nums[i]
                int pickLeft = nums[i] + dp[i + 1][j][1];  // player1's score
                int oppLeft = dp[i + 1][j][0];             // player2's score in next round

                // Option 2: player1 picks nums[j]
                int pickRight = nums[j] + dp[i][j - 1][1];
                int oppRight = dp[i][j - 1][0];

                // Choose the better option for player1
                if (pickLeft >= pickRight) {
                    dp[i][j][0] = pickLeft;
                    dp[i][j][1] = oppLeft;
                } else {
                    dp[i][j][0] = pickRight;
                    dp[i][j][1] = oppRight;
                }
            }
        }

        return dp[0][n - 1][0] >= dp[0][n - 1][1];
    }
};