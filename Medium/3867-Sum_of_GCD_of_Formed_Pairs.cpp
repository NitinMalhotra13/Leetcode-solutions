class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = 0;
        vector<int> prefixGcd(nums.size());

        for (int i = 0; i < nums.size(); i++){
            maxi = max(maxi,nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        int left  = 0, right = prefixGcd.size() - 1;
        long long ans = 0;

        sort(prefixGcd.begin(), prefixGcd.end());

        while (left < right){
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            right--; 
            left++;
        }
        return ans;
    }
};
