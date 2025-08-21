class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<int> height(col, 0);
        int total = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }

            for (int i = 0; i < col; i++) {
                if (height[i] > 0) {
                    int minHeight = height[i];
                    for (int j = i; j >= 0 && height[j] > 0; j--) {
                        minHeight = min(minHeight, height[j]);
                        total += minHeight;
                    }
                }
            }
        }
        return total;
    }
};
