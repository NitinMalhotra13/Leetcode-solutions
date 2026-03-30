class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int cnt[2][26] = {};

        for (int i = 0; i < s1.size(); i++) {
            cnt[i % 2][s1[i] - 'a']++;
            cnt[i % 2][s2[i] - 'a']--;
        }

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 26; j++)
                if (cnt[i][j]) return false;

        return true;
    }
};
