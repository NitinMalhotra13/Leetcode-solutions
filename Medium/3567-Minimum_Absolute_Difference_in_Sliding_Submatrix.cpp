class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        int m=g.size(), n=g[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));

        for(int i=0;i<=m-k;i++)
            for(int j=0;j<=n-k;j++){
                set<int> s;

                for(int x=i;x<i+k;x++)
                    for(int y=j;y<j+k;y++)
                        s.insert(g[x][y]);

                if(s.size() <= 1){
                    ans[i][j] = 0;
                    continue;
                }

                int mn = INT_MAX;
                auto it = s.begin(), prev = it++;

                for(; it!=s.end(); ++it, ++prev)
                    mn = min(mn, *it - *prev);

                ans[i][j] = mn;
            }
        return ans;
    }
};
