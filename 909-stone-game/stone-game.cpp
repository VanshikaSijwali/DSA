class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: single pile remaining
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill table for sub-array lengths from 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                int takeStart = piles[i] - dp[i + 1][j];
                int takeEnd   = piles[j] - dp[i][j - 1];

                dp[i][j] = max(takeStart, takeEnd);
            }
        }

        // Alice wins if her final relative lead from piles[0...n-1] is > 0
        return dp[0][n - 1] > 0;
    }
};