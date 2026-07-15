class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int secondlargest = -1;

        for (char c : s) {
            if (isdigit(c)) {
                int digit = c - '0';

                if (digit > largest) {
                    secondlargest = largest;
                    largest = digit;
                }
                else if (digit >= secondlargest && digit != largest) {
                    secondlargest = digit;
                }
            }
        }
        return secondlargest;
    }
};
