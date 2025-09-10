class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> know(m);
        for (int i = 0; i < m; i++) for (int l : languages[i]) know[i].insert(l);
        unordered_set<int> need;
        for (auto& f : friendships) {
            int u = f[0]-1, v = f[1]-1, ok = 0;
            for (int l : know[u]) if (know[v].count(l)) { ok = 1; break; }
            if (!ok) need.insert(u), need.insert(v);
        }
        if (need.empty()) return 0;
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int p : need) if (!know[p].count(lang)) cnt++;
            ans = min(ans, cnt);
        }
        return ans;
    }
};
