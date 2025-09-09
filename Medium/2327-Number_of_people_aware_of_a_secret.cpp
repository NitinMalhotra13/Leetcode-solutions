class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9+7;
        vector<long long> dp(n+1); 
        dp[1]=1;
        long long share=0, ans=0;
        for(int d=2; d<=n; d++){
            if(d-delay>=1) share=(share+dp[d-delay])%MOD;
            if(d-forget>=1) share=(share-dp[d-forget]+MOD)%MOD;
            dp[d]=share;
        }
        for(int d=n-forget+1; d<=n; d++) ans=(ans+dp[d])%MOD;
        return ans;
    }
};
