class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string a = s, b = s;
        for (char c : s) {
            if (c != '9') {
                for (char &x : a) if (x == c) x = '9';
                break;
            }
        }
        for (char c : s) {
            if (c != '0') {
                for (char &x : b) if (x == c) x = '0';
                break;
            }
        }
        return stoi(a) - stoi(b);
    }
};
