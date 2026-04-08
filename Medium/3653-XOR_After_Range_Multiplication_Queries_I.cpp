class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        const int MOD = 1e9+7;
        
        for(auto &x : q){
            int l = x[0], r = x[1], k = x[2], v = x[3];
            for(int i = l; i <= r; i += k)
                nums[i] = (1LL * nums[i] * v) % MOD;
        }
        
        int ans = 0;
        for(int x : nums) ans ^= x;
        return ans;
    }
};
