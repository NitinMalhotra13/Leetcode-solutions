class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, maxi = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                min++;
                maxi++;
            }
            else if (s[i] == ')'){
                min--;
                maxi--;
            }
            else{
                min--;
                maxi++;
            }
            if (min < 0){
                min = 0;
            }
            if (maxi < 0){
                return false;
            }
        }
        return min == 0;
    }
};
