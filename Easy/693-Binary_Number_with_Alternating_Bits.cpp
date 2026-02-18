class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a = n ^ (n >> 2);

        int count = 0;
        while (a > 0) {
            if (a & 1)
                count++;
            a >>= 1;
        }
        return count == 1;
    }
};
