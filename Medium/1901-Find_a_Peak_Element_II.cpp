class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int start = 0, end = m - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            int left  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            }
            else if (mat[maxRow][mid] < right) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return {-1, -1};
    }
};
