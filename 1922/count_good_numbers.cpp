#include <iostream>

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long total = 1;
        for (long long i = 0; i < n; i++) {
            if ((i & 1) == 0) { // check for evenness
                total = (5 * (total % 1000000007)) % 1000000007;
            } else {
                total = (4 * (total % 1000000007)) % 1000000007; // 2, 3, 5, 7 are single-digit prime numbers --> 4 possibilities
            }
        }
        return total;
    }
};

int main() {
    Solution solution;
    std::cout << "n = 1: " << solution.countGoodNumbers(1) << "\n";
    std::cout << "n = 4: " << solution.countGoodNumbers(4) << "\n";
    std::cout << "n = 50: " << solution.countGoodNumbers(50) << "\n";
    std::cout << "n = 10^10: " << solution.countGoodNumbers(10000000000) << "\n";
}
