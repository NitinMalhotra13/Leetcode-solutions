class Solution {
public:
    long long totalhours(vector<int>& piles, int speed) {
        long long htotal = 0;
        for (int i = 0; i < piles.size(); i++) {
            htotal += (piles[i] + speed - 1) / speed;
        }
        return htotal;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            long long reqHours = totalhours(piles, mid);

            if (reqHours <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
