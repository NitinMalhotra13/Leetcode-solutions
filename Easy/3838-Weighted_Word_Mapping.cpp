class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string& word : words) {
            int mod = 0;

            for (char c : word)
                mod = (mod + weights[c - 'a']) % 26;

            ans += char('z' - mod);
        }

        return ans;
    }
};
