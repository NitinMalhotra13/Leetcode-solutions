class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int mask = 0; mask < (1 << n); mask++){
            vector<int> subsets;
            for (int i = 0; i < n; i++){
                if((mask >> i) & 1){
                    subsets.push_back(nums[i]);
                }
            }
            ans.push_back(subsets);
        }
        return ans;
    }
};
