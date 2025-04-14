#include <iostream>
#include <string>

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            std::cout << "Beginning with i = " << i << "\n";
            std::string current = std::to_string(i);
            int length = current.size();
            if ((length % 2) == 0) {
                std::cout << i << " is divisible by 2!\n";
                int left = 0;
                int right = 0;
                int j = 0;
                for (auto digit : current) {
                    if (j < length / 2) {
                        left += digit - '0';
                    } else {
                        right += digit - '0';
                    }
                    j++;
                }
                if (left == right) {
                    count++;
                }
                std::cout << "i: " << i << ", left: " << left << ", right: " << right << std::endl;
                std::cout << "count: " << count << "\n\n";
            }
        }
        return count;
    }
};

int main () {
    Solution solution;
    std::cout << solution.countSymmetricIntegers(1, 100) << "\n";
}
