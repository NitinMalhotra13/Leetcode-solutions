class Solution {
public:
    string largestGoodInteger(string num) {
        for (char d = '9'; d >= '0'; --d) {
            string s(3, d);
            if (num.find(s) != string::npos) return s;
        }
        return "";
    }
};
