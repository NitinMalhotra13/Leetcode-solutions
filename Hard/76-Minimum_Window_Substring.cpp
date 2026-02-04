class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char c : t) mp[c]++;

        int l = 0, need = t.size();
        int start = 0, minLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {

            if (mp[s[r]] > 0) need--;
            mp[s[r]]--;

            while (need == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                mp[s[l]]++;
                if (mp[s[l]] > 0) need++;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
