class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> h(m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                h[j] = matrix[i][j] ? h[j] + 1 : 0;

            vector<int> temp = h;
            sort(temp.rbegin(), temp.rend());

            for(int j = 0; j < m; j++)
                ans = max(ans, temp[j] * (j + 1));
        }
        return ans;
    }
};
