class Solution {
public:
    bool check(int mid, int n, vector<vector<pair<int,int>>> &adj,
               vector<int> &indeg, vector<bool> &online, long long k) {

        vector<int> deg = indeg;
        vector<long long> dp(n, LLONG_MAX);
        queue<int> q;

        for(int i = 0; i < n; i++)
            if(deg[i] == 0)
                q.push(i);

        dp[0] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto &[v, w] : adj[u]) {

                if(w >= mid && dp[u] != LLONG_MAX &&
                   (v == n - 1 || online[v]))
                    dp[v] = min(dp[v], dp[u] + w);

                if(--deg[v] == 0)
                    q.push(v);
            }
        }
        return dp[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n);

        int hi = 0;

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
            hi = max(hi, e[2]);
        }

        int lo = 0, ans = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(check(mid, n, adj, indeg, online, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
