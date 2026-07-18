class Solution {
public:
    int findGCD(vector<int>& nums) {
        // int ans = 0;

        // sort(nums.begin(), nums.end());
        
        // ans = gcd(nums[0], nums[nums.size()-1]);
        // return ans;


        int left = 0, right = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > nums[right]) right = i;

            if (nums[i] < nums[left]) left = i;
        }
        return gcd(nums[left], nums[right]);
    }
};
