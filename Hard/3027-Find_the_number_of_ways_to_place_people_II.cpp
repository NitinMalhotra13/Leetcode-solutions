class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[j][1] <= points[i][1] && points[j][1] > maxY) {
                    ++ans;
                    maxY = points[j][1];
                }
            }
        }
        return ans;
    }
};
