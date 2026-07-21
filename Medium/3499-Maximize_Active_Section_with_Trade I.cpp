class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<pair<char,int>> g;
        for (char c : t) {
            if (g.empty() || g.back().first != c)
                g.push_back({c, 1});
            else
                g.back().second++;
        }

        int ans = ones;

        // Pattern: 0 - 1 - 0
        for (int i = 1; i + 1 < g.size(); i++) {
            if (g[i].first == '1' &&
                g[i-1].first == '0' &&
                g[i+1].first == '0') {

                ans = max(ans, ones + g[i-1].second + g[i+1].second);
            }
        }
        return ans;
    }
};
