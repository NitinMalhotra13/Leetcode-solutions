class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mod = 12345;
        
        vector<int> a;
        for(auto &r : grid)
            for(int x : r) a.push_back(x % mod);
        
        int sz = a.size();
        vector<int> pre(sz,1), suf(sz,1);
        
        for(int i=1;i<sz;i++)
            pre[i] = (pre[i-1] * a[i-1]) % mod;
        
        for(int i=sz-2;i>=0;i--)
            suf[i] = (suf[i+1] * a[i+1]) % mod;
        
        vector<vector<int>> res(n, vector<int>(m));
        
        for(int i=0;i<sz;i++)
            res[i/m][i%m] = (pre[i] * suf[i]) % mod;
        
        return res;
    }
};
