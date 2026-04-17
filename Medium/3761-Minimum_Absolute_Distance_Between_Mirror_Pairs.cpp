class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp.count(num)) {
                mini = min(mini, i - mp[num]);
            }
            int rev = reverseNum(num);
            mp[rev] = i;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
