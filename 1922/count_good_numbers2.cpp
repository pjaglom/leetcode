#include <iostream>

class Solution {
public:
    int magic = 1000000007;
    long long my_pow(long long x, long long n) {
        long long result = 1;
        while (n > 0) {
            if (n & 1) {
                result = ((result) * (x)) % magic;
            }
            x = ((x) * (x)) % magic;
            n >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long total = 1;
        if (n == 1) {
            return 5;
        } else if ((n & 1) == 0) { // n is even
            total = ((total) * (my_pow(2, 2 * (n/2)) % magic)) % magic;
            total = ((total) * (my_pow(5, n/2) % magic)) % magic;
        } else {
            total = ((total) * (my_pow(2, 2 * (n/2)) % magic)) % magic;
            total = ((total) * (my_pow(5, (n/2) + 1) % magic)) % magic;
        }
        return total;
    }
};

int main() {
    Solution solution;
    std::cout << "n = 1: " << solution.countGoodNumbers(1) << "\n";
    std::cout << "n = 3: " << solution.countGoodNumbers(3) << "\n";
    std::cout << "n = 4: " << solution.countGoodNumbers(4) << "\n";
    std::cout << "n = 31: " << solution.countGoodNumbers(31) << "\n";
    std::cout << "n = 32: " << solution.countGoodNumbers(32) << "\n";
    std::cout << "n = 33: " << solution.countGoodNumbers(33) << "\n";
    std::cout << "n = 50: " << solution.countGoodNumbers(50) << "\n";
    std::cout << "n = 65: " << solution.countGoodNumbers(65) << "\n";
    std::cout << "n = 100: " << solution.countGoodNumbers(100) << "\n";
    std::cout << "n = 300: " << solution.countGoodNumbers(300) << "\n";
    std::cout << "n = 1000: " << solution.countGoodNumbers(1000) << "\n";
    std::cout << "n = 10000: " << solution.countGoodNumbers(10000) << "\n";
    std::cout << "n = 100000: " << solution.countGoodNumbers(100000) << "\n";
    std::cout << "n = 1000000: " << solution.countGoodNumbers(1000000) << "\n";
    std::cout << "n = 10000000: " << solution.countGoodNumbers(10000000) << "\n";
    std::cout << "n = 100000000: " << solution.countGoodNumbers(100000000) << "\n";
    std::cout << "n = 1000000000: " << solution.countGoodNumbers(1000000000) << "\n";
    std::cout << "n = 10^10: " << solution.countGoodNumbers(10000000000) << "\n";
}
