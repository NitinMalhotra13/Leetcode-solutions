class Solution {
public:
    int minOperations(string s) {
        
        int n = s.size();
        int p1 = 0, p2 = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] != (i % 2 ? '1' : '0'))
                p1++;
            
            if(s[i] != (i % 2 ? '0' : '1'))
                p2++;
        }
        
        return min(p1, p2);
    }
};
