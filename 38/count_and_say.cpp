#include <string>
#include <iostream>

class Solution {
public:
    std::string runLengthEncode(std::string str) {
        std::string result = "";
        int tempCount = 0;
        for (long unsigned int i = 0; i < str.length(); i++) {
            tempCount++;
            if (str[i] != str[i + 1]) {
                result.append(std::to_string(tempCount));
                result.push_back(str[i]);
                tempCount = 0;
            }
        }
        return result;
    }
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return runLengthEncode(countAndSay(n - 1));
    }
};

int main() {
    Solution solution;
    std::cout << "1: " << solution.runLengthEncode("1");
    std::cout << "11: " << solution.runLengthEncode("11");
    std::cout << "21: " << solution.runLengthEncode("21");
    std::cout << "21: " << solution.runLengthEncode("21");
    std::cout << "CountAndSay(30): " << solution.countAndSay(30);

}
