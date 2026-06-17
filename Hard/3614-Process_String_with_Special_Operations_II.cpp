class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for (char c : s) {
            if ('a' <= c && c <= 'z') len++;
            else if (c == '*') len = max(0LL, len - 1);
            else if (c == '#') len *= 2;
        }

        if (k >= len) return '.';

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '#') {
                len /= 2;
                k %= len;
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
            else if (c == '*') {
                len++;
            }
            else {
                len--;
                if (k == len) return c;
            }
        }
        return '.';
    }
};
