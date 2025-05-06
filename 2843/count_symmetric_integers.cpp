#include <iostream>
#include <string>

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            std::string current = std::to_string(i);
            int length = current.size();
            if ((length % 2) == 0) {
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
            }
        }
        return count;
    }
};
int main () {
    Solution solution;
    std::cout << solution.countSymmetricIntegers(1, 100) << "\n";
}
