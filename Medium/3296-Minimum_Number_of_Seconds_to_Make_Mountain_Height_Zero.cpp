class Solution {
public:
    
    bool can(long long t, int h, vector<int>& wt){
        
        long long removed = 0;
        
        for(long long w : wt){
            
            long long val = (2*t) / w;
            
            long long k = (sqrt(1 + 4*val) - 1) / 2;
            
            removed += k;
            
            if(removed >= h) return true;
        } 
        return false;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 0, r = 1e18, ans = r;
        
        while(l <= r){
            
            long long mid = (l + r) / 2;
            
            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        } 
        return ans;
    }
};
