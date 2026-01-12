class Solution {
public:
    int countSubarrays(vector<int>& nums, int limit) {
        int subarrays = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= limit) {
                sum += nums[i];
            } else {
                subarrays++;
                sum = nums[i];
            }
        }
        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int subarrays = countSubarrays(nums, mid);

            if (subarrays > k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};
