class Solution {
public:
    int maximumAmount(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector dp(n, vector(m, vector<int>(3, -1e9)));
        
        dp[0][0][0]=a[0][0];
        if(a[0][0]<0) dp[0][0][1]=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                for(int k=0;k<3;k++){
                    int val=a[i][j];
                    
                    if(i>0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k]+val);
                    if(j>0) dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k]+val);
                    
                    if(val<0 && k>0){
                        if(i>0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]);
                        if(j>0) dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }  
        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};
