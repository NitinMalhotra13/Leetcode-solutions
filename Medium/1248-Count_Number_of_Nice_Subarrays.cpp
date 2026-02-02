class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        auto atMost = [&](int K){
            if (K < 0) return 0;
            int l = 0, count = 0, odd = 0;
            for (int r = 0; r < nums.size(); r++){
                if (nums[r] % 2) odd++;
                while (odd > K){
                    if (nums[l] % 2) odd--;
                    l++;
                }
                count += r - l + 1;
            }
            return count;
        };
        return atMost(k) - atMost(k - 1);
    }
};
