class Solution {
public:
    int finddays(vector<int> weights, int limit){
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++){
            if (weights[i] + load > limit){
                days++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);

        while (start <= end){
            int mid = start + (end - start) / 2;

            int numberofdays = finddays(weights , mid);
            if (numberofdays <= days){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }
};
