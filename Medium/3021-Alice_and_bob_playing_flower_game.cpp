class Solution {
public:
    long long flowerGame(int n, int m) {
       long long xOdd = (n + 1LL) / 2, xEven = n / 2;
        long long yOdd = (m + 1LL) / 2, yEven = m / 2;
        return xOdd * yEven + xEven * yOdd; 
    }
};
