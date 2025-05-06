#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        unsigned long n = differences.size();
        long long min;
        long long max;
        if (differences[0] < 0) {
            min = differences[0];
            max = 0;
        } else {
            min = 0;
            max = differences[0];
        }
        vector<long long> pseudoHidden(n + 1);
        pseudoHidden[0] = 0;
        for (unsigned long i = 0; i < n; i++) {
            pseudoHidden[i + 1] = pseudoHidden[i] + differences[i];;
            if (pseudoHidden[i+1] > max) max = pseudoHidden[i+1];
            if (pseudoHidden[i+1] < min) min = pseudoHidden[i+1];
        }
        int result = 0;
        if ((upper - lower) >= (max - min)) {
            result = (upper - lower) - (max - min) + 1;
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> case1 = {1,-3,4};
    std::cout << "case 1: " << solution.numberOfArrays(case1, 1, 6) << "\n";
}
