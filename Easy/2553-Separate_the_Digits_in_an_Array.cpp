class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (auto &n : nums){
            string s = to_string(n);

            for (auto i : s){
                ans.push_back(i - '0');
            }
        }
        return ans;
    }
};
