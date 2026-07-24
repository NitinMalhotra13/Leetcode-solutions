class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bitset<2048> ans;
        unordered_set<int> xorpair;

        for (int x : nums){
            ans.set(x);
        }

        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1;j < nums.size(); j++){
                xorpair.insert(nums[i] ^ nums[j]);
            }
        }

        for (int p : xorpair){
            for (int x : nums){
                ans.set(p ^ x);
            }
        }
        return ans.count();
    }
};
