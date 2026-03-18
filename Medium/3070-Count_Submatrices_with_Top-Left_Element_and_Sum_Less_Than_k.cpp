class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i) grid[i][j] += grid[i-1][j];
                if(j) grid[i][j] += grid[i][j-1];
                if(i && j) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) ans++;
            }
        }
        return ans;
    }
};
