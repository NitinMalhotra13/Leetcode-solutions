class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];

        // priority_queue<int, vector<int>, greater<int>> minheap;

        // for (int x : nums){
        //     minheap.push(x);

        //     if (minheap.size() > k){
        //         minheap.pop();
        //     }
        // }
        // return minheap.top();
    
        priority_queue<int> maxheap;

        for (int x : nums){
            maxheap.push(x);
        }

        for (int i = 1; i < k; i++){
            maxheap.pop();
        }

        return maxheap.top();
    }
};
