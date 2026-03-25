class Solution {
public:
    vector<int> buildLPS(string p) {
        int n = p.size();
        vector<int> lps(n, 0);

        int len = 0;
        for (int i = 1; i < n; ) {
            if (p[i] == p[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) len = lps[len - 1];
                else i++;
            }
        }
        return lps;
    }

    int strStr(string h, string p) {
        int n = h.size(), m = p.size();
        vector<int> lps = buildLPS(p);

        int i = 0, j = 0;

        while (i < n) {
            if (h[i] == p[j]) {
                i++; j++;
            }

            if (j == m) return i - j;

            else if (i < n && h[i] != p[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
};
