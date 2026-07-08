class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        int sum, cnt;
        Node(long long v = 0, int s = 0, int c = 0)
            : val(v), sum(s), cnt(c) {}
    };

    vector<Node> seg;
    vector<long long> p10;
    string str;

    Node merge(Node a, Node b) {
        return Node(
            (a.val * p10[b.cnt] + b.val) % MOD,
            a.sum + b.sum,
            a.cnt + b.cnt
        );
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            if (str[l] != '0') {
                int d = str[l] - '0';
                seg[idx] = Node(d, d, 1);
            }
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(
            query(idx * 2, l, mid, ql, qr),
            query(idx * 2 + 1, mid + 1, r, ql, qr)
        );
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        str = s;
        int n = s.size();

        seg.assign(4 * n + 5, Node());

        p10.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p10[i] = (p10[i - 1] * 10) % MOD;

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((1LL * cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};
