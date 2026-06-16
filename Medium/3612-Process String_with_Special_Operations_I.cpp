class Solution {
public:
    string processStr(string s) {
        string res;

        for (char c : s) {
            if (islower(c)) res += c;
            else if (c == '*') {
                if (!res.empty()) res.pop_back();
            }
            else if (c == '#') res += res;
            else reverse(res.begin(), res.end());
        }

        return res;
    }
};
