class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        int units = (n + 24) / 25;
        vector<vector<double>> dp(units + 1, vector<double>(units + 1, -1.0));
        return solve(units, units, dp);
    }
private:
    double solve(int a, int b, vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b] != -1.0) return dp[a][b];
        return dp[a][b] = 0.25 * (
            solve(a - 4, b, dp) +
            solve(a - 3, b - 1, dp) +
            solve(a - 2, b - 2, dp) +
            solve(a - 1, b - 3, dp)
        );
    }
};
