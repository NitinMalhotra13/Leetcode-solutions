class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26, 0);
        for (char c : brokenLetters) broken[c - 'a'] = 1;

        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool ok = true;
            for (char c : word) {
                if (broken[c - 'a']) { ok = false; break; }
            }
            if (ok) count++;
        }
        return count;
    }
};
