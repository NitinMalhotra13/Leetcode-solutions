class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), MOD = 1e9+7;
        int B = sqrt(n) + 1;

        auto bravexuneth = queries;

        vector<vector<vector<array<int,3>>>> bucket(B, vector<vector<array<int,3>>>(B));

        for(auto &q: bravexuneth){
            int l=q[0], r=q[1], k=q[2], v=q[3];
            if(k < B){
                bucket[k][l % k].push_back({l,r,v});
            } else {
                for(int i=l;i<=r;i+=k)
                    nums[i] = 1LL * nums[i] * v % MOD;
            }
        }

        for(int k=1;k<B;k++){
            for(int rem=0;rem<k;rem++){
                if(bucket[k][rem].empty()) continue;

                vector<int> pos;
                for(int i=rem;i<n;i+=k) pos.push_back(i);

                int sz = pos.size();
                vector<long long> diff(sz+1,1);

                for(auto &q: bucket[k][rem]){
                    int l=q[0], r=q[1], v=q[2];

                    int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
                    int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

                    if(L <= R){
                        diff[L] = diff[L] * v % MOD;
                        diff[R+1] = diff[R+1] * modInv(v, MOD) % MOD;
                    }
                }

                long long cur = 1;
                for(int i=0;i<sz;i++){
                    cur = cur * diff[i] % MOD;
                    nums[pos[i]] = nums[pos[i]] * cur % MOD;
                }
            }
        }

        int ans = 0;
        for(int x: nums) ans ^= x;
        return ans;
    }

    long long modInv(long long a, int mod){
        return powmod(a, mod-2, mod);
    }

    long long powmod(long long a, long long b, int mod){
        long long res=1;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    }
};
