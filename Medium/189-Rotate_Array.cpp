class Solution {
public:
    void reversePart(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reversePart(nums, 0, n - 1);
        reversePart(nums, 0, k - 1);
        reversePart(nums, k, n - 1);
    }
};
