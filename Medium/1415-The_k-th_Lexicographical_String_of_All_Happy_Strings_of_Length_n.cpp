class Solution {
public:
    string getHappyString(int n, int k) {
        
        int total = 3 * (1 << (n-1));
        if(k > total) return "";
        
        string ans = "";
        vector<char> chars = {'a','b','c'};
        
        for(int i=0;i<n;i++){
            
            int block = 1 << (n-i-1);
            
            for(char c : chars){
                
                if(!ans.empty() && ans.back()==c) continue;
                
                if(k > block){
                    k -= block;
                }
                else{
                    ans += c;
                    break;
                }
            }
        }
        return ans;
    }
};
