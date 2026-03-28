class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePath(m - 1, n - 1, dp);
    }

    int uniquePath(int m, int n, vector<vector<int>> &dp) {
        if (m == 0 && n == 0) return 1;
        
        if (m < 0 || n < 0) return 0;

        if (dp[m][n] != -1) return dp[m][n];

        int up = uniquePath(m - 1, n, dp);
        int left = uniquePath(m, n - 1, dp);

        return dp[m][n] = up + left;
    }
};
