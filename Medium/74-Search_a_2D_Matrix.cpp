class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int start = 0;
        int end = m * n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int r = mid / m;
            int c = mid % m;
            if (mat[r][c] == target) {
                return true;
            } else if (mat[r][c] < target) {
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return false;
    }
};
