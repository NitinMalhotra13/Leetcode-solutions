class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()){
            return s;
        }
        string result;
        int cycle = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += cycle) {
                result += s[j];

                int diag = j + cycle - 2 * i;
                if (i != 0 && i != numRows - 1 && diag < s.size())
                    result += s[diag];
            }
        }
        return result;
    }
};
