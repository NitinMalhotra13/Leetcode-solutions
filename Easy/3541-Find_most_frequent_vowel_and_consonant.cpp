class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        int maxVowel = 0, maxCons = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                if (freq[i] > maxVowel) maxVowel = freq[i];
            } else {
                if (freq[i] > maxCons) maxCons = freq[i];
            }
        }
        return maxVowel + maxCons;
    }
};
