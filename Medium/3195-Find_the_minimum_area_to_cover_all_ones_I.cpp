class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int minRow = INT_MAX, minCol = INT_MAX;
        int maxRow = INT_MIN, maxCol = INT_MIN;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    minCol = min(minCol, c);
                    maxRow = max(maxRow, r);
                    maxCol = max(maxCol, c);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
