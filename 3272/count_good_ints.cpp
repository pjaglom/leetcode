#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string x_str = std::to_string(x);
        auto length = x_str.length();
        for (long unsigned int i = 0; i < length / 2; i++) {
            //std::cout << "x_str: " << x_str << ", i: " << i << ", x_str[i]: " << x_str[i] << ", x_str[length-1-i]: " << x_str[length-1-i] << "\n";
            if (x_str[i] != x_str[length-1-i]) {
                return false;
            }
        }
        return true;
    }

    bool isKpalindrome(int x, int k) {
        return isPalindrome(x) && ((x % k) == 0);
    }

    long long my_pow(long long x, long long n) {
        long long result = 1;
        while (n > 0) {
            if (n & 1) {
                result = ((result) * (x));
            }
            x = ((x) * (x));
            n >>= 1;
        }
        return result;
    }

    long long factorial(unsigned int n) {
        long long result = 1;
        while (n > 1) {
            result *= n;
            n--;
        }
        return result;
    }

    long long countPermutations(int x) {
        std::unordered_map<char, int> charmap;
        std::string x_str = std::to_string(x);
        auto length = x_str.length();
        if (length == 1) {
            return 1;
        }
        for (char c : x_str) {
            charmap.insert({c, 0});
            charmap[c]++;
        }
        long long result = 1;
        result *= factorial(length);
        for (std::pair<char, int> entry : charmap) {
            result /= factorial(entry.second);
        }
        if (charmap.find('0') != charmap.end()) {
            long long startZero = 1;
            startZero *= factorial(length - 1);
            for (std::pair<char, int> entry : charmap) {
                if (entry.first == '0') {
                    startZero /= factorial(entry.second - 1);
                } else {
                    startZero /= factorial(entry.second);
                }
            }
            result -= startZero;
        }
        return result;
    }

    int sortedNumber(int x) {
        std::string x_str = std::to_string(x);
        std::vector<char> x_vec;
        for (char c : x_str) {
            x_vec.push_back(c);
        }
        std::sort(x_vec.begin(), x_vec.end(), std::greater<int>());
        char new_x[x_str.length() + 1];
        for (long unsigned int i = 0; i < x_str.length(); i++) {
            new_x[i] = x_vec[i];
        }
        new_x[x_str.length()] = '\0';
        int result = std::stoi(new_x);
        return result;
    }
    long long countGoodIntegers(int n, int k) {
        int low = my_pow(10, n-1);
        int high = my_pow(10, n);
        long long count = 0;
        std::unordered_set<int> good_ints;
        for (int i = low; i < high; i++) {
            if (isKpalindrome(i, k)) {
                std::cout << i << " is k-palindromic in " << k << "!\n";
                good_ints.insert(sortedNumber(i));
            }
        }
        for (int good_int : good_ints) {
            count += countPermutations(good_int);
            std::cout << "Count is now " << count << "\n";
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::cout << "7: " << solution.isPalindrome(7) << "\n";
    std::cout << "10: " << solution.isPalindrome(10) << "\n\n";
    std::cout << "11: " << solution.isPalindrome(11) << "\n\n";
    std::cout << "151: " << solution.isPalindrome(151) << "\n\n";
    std::cout << "2335332: " << solution.isPalindrome(2335332) << "\n\n";
    std::cout << "23355332: " << solution.isPalindrome(23355332) << "\n\n";
    std::cout << "23255332: " << solution.isPalindrome(23255332) << "\n\n";
    std::cout << "permutations of 5: " << solution.countPermutations(5) << "\n\n";
    std::cout << "permutations of 52: " << solution.countPermutations(52) << "\n\n";
    std::cout << "permutations of 352: " << solution.countPermutations(352) << "\n\n";
    std::cout << "permutations of 33: " << solution.countPermutations(33) << "\n\n";
    std::cout << "permutations of 313: " << solution.countPermutations(313) << "\n\n";
    std::cout << "Count of good ints of n = 3, k = 5: " << solution.countGoodIntegers(3, 5) << "\n\n";
    std::cout << "Count of good ints of n = 1, k = 4: " << solution.countGoodIntegers(1, 4) << "\n\n";
    std::cout << "Count of good ints of n = 5, k = 6: " << solution.countGoodIntegers(5, 6) << "\n\n";
    std::cout << "Count of good ints of n = 7, k = 5: " << solution.countGoodIntegers(7, 5) << "\n\n";
}
