class Solution {
public:
    int maxProductPath(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size(), MOD=1e9+7;
        vector<vector<long long>> mx(m, vector<long long>(n)), mn=mx;

        mx[0][0]=mn[0][0]=g[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                long long val = g[i][j];

                if(i==0){
                    mx[i][j]=mn[i][j]=mx[i][j-1]*val;
                }
                else if(j==0){
                    mx[i][j]=mn[i][j]=mx[i-1][j]*val;
                }
                else{
                    long long a=mx[i-1][j]*val;
                    long long b=mn[i-1][j]*val;
                    long long c=mx[i][j-1]*val;
                    long long d=mn[i][j-1]*val;

                    mx[i][j]=max({a,b,c,d});
                    mn[i][j]=min({a,b,c,d});
                }
            }
        }
        long long res = mx[m-1][n-1];
        return res<0 ? -1 : res%MOD;
    }
};
