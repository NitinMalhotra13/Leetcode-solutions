class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
       vector<double> numbers(cards.begin(), cards.end());
        return canMake24(numbers); 
    }

    bool canMake24(vector<double> numbers) {
        if (numbers.size() == 1) 
            return fabs(numbers[0] - 24) < 1e-6;

        for (int firstIndex = 0; firstIndex < numbers.size(); firstIndex++) {
            for (int secondIndex = 0; secondIndex < numbers.size(); secondIndex++) {
                if (firstIndex == secondIndex) continue;

                vector<double> remainingNumbers;
                for (int idx = 0; idx < numbers.size(); idx++) {
                    if (idx != firstIndex && idx != secondIndex) {
                        remainingNumbers.push_back(numbers[idx]);
                    }
                }

                vector<double> results = computeResults(numbers[firstIndex], numbers[secondIndex]);
                for (double resultValue : results) {
                    remainingNumbers.push_back(resultValue);
                    if (canMake24(remainingNumbers)) return true;
                    remainingNumbers.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> computeResults(double a, double b) {
        vector<double> results = {a + b, a - b, b - a, a * b};
        if (fabs(b) > 1e-6) results.push_back(a / b);
        if (fabs(a) > 1e-6) results.push_back(b / a);
        return results;
    }
};
