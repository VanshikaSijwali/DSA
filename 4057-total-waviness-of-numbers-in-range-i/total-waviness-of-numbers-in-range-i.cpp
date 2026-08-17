class Solution {
    // DP array to memoize all 1000 possible 3-digit triplets (000 to 999)
    int dp[10][10][10];

    int checkTriplet(int f, int m, int l) {
        if (dp[f][m][l] != -1) return dp[f][m][l];

        if ((f < m && l < m) || (f > m && l > m)) {
            return dp[f][m][l] = 1;
        }
        return dp[f][m][l] = 0;
    }

public:
    int totalWaviness(int num1, int num2) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i = num1; i <= num2; i++) {
            string s = to_string(i);
            int n = s.length();

            // Slide a 3-digit window over the string
            for (int j = 0; j <= n - 3; j++) {
                int f = s[j] - '0';
                int m = s[j + 1] - '0';
                int l = s[j + 2] - '0';

                ans += checkTriplet(f, m, l);
            }
        }
        return ans;
    }
};