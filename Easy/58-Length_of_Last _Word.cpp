class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1, len = 0;

        while(i >= 0 && s[i] == ' ') i--;     // skip spaces
        while(i >= 0 && s[i] != ' ') len++, i--; // count word

        return len;
    }
};
