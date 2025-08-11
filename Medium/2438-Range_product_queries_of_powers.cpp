class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1'000'000'007;
        vector<int> powers;
        while (n) {
            int x = n & -n;
            powers.push_back(x);
            n -= x;
        }
        vector<int> ans;
        for (auto& q : queries) {
            long long prod = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                prod = (prod * powers[i]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
