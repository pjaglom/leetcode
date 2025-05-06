#include <string>
#include <iostream>

class Solution {
public:
    std::string runLengthEncode(std::string str) {
        std::string result = "";
        int tempCount = 0;
        for (int i = 0; i < str.length(); i++) {
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
        std::string result = "1";
        for (int i = 2; i <=n; i++) {
            result = runLengthEncode(result);
        }
        return result;
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
