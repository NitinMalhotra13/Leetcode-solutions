class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int l = log2(n);
        if (n > 2){
            return pow(2,l+1);
        }
        return pow(2,l);
    }
};
