class Solution {
public:
    bool isPalindrome(string s) {
        return check(s, 0, s.size() - 1);
    }

    bool check(string &s, int i, int j) {
        if (i >= j) return true;

        if (!isalnum(s[i])) return check(s, i + 1, j);
        if (!isalnum(s[j])) return check(s, i, j - 1);

        if (tolower(s[i]) != tolower(s[j]))
            return false;

        return check(s, i + 1, j - 1);
    }
};
