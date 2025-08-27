class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dirs[4][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};
        vector dp(n, vector(m, vector(4, vector<int>(2, -1))));
        auto inside = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        function<int(int,int,int,int,int)> dfs = [&](int i, int j, int dir, int canTurn, int expect) {
            if (!inside(i, j) || grid[i][j] != expect) return 0;
            int &res = dp[i][j][dir][canTurn];
            if (res != -1) return res;
            int nextExpect = (expect == 2 ? 0 : 2);
            int ni = i + dirs[dir][0], nj = j + dirs[dir][1];
            res = 1 + dfs(ni, nj, dir, canTurn, nextExpect);
            if (canTurn) {
                int newDir = (dir + 1) % 4;
                int ti = i + dirs[newDir][0], tj = j + dirs[newDir][1];
                res = max(res, 1 + dfs(ti, tj, newDir, 0, nextExpect));
            }
            return res;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        ans = max(ans, dfs(i, j, dir, 1, 1));
                    }
                }
            }
        }
        return ans;
    }
};
