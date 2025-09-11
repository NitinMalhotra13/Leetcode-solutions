class Solution {
public:
    string sortVowels(string s) {
        string v = "";
        for (char c : s) if (string("AEIOUaeiou").find(c) != string::npos) v += c;
        sort(v.begin(), v.end());
        int j = 0;
        for (char& c : s) if (string("AEIOUaeiou").find(c) != string::npos) c = v[j++];
        return s;
    }
};
