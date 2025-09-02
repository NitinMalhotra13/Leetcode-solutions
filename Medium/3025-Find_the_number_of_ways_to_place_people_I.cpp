class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
       int ans = 0;
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int y1 = points[i][1], y2 = points[j][1];
                if (y2 <= y1 && y2 > maxY) {
                    ++ans;
                    maxY = y2;
                }
            }
        }
        return ans; 
    }
};
