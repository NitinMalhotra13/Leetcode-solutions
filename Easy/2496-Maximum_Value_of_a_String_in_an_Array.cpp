class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;

        for (auto &s : strs) {
            bool num = true;
            for (char c : s) {
                if (!isdigit(c)) {
                    num = false;
                    break;
                }
            }
            ans = max(ans, num ? stoi(s) : (int)s.size());
        }
        return ans;
    }
};
