class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos[n+1];

        for (int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        } 

        int ans = INT_MAX;
        for (auto i : pos){
            if (i.size() < 3){
                continue;
            }
            for (int j = 1;j < (i.size() - 1); j++){
                ans = min (ans, i[j] - i[j-1] + i[j+1] - i[j] + i[j+1] - i[j-1]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
