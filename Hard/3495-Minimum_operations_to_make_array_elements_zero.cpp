class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& qr : queries) {
            int l = qr[0], r = qr[1];
            ans += (getOps(r) - getOps(l - 1) + 1) / 2;
        }
        return ans;
    }
    long long getOps(int n) {
        long long res = 0;
        int ops = 0;
        for (long long pw = 1; pw <= n; pw *= 4) {
            ops++;
            long long left = pw;
            long long right = min<long long>(n, pw * 4 - 1);
            res += (right - left + 1) * ops;
        }
        return res;
    }
};
