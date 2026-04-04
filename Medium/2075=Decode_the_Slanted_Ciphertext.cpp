class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if(rows == 1) return s;
        
        int n = s.size(), cols = n / rows;
        string res;
        
        for(int j = 0; j < cols; j++){
            int i = 0, k = j;
            while(i < rows && k < cols){
                res += s[i * cols + k];
                i++, k++;
            }
        }
        while(!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};
