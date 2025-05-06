#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int countLargestGroup(int n) {
        int largestGroupSize = 0;
        int numLargestGroups = 0;
        std::unordered_map<int, size_t> groups;
        std::string n_str = std::to_string(n);
        int length = n_str.length();
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            std::string i_str = std::to_string(i);
            int pow = 0;
            for (char c : i_str) {
                temp += c - '0';
            }
            groups.insert({temp, 0});
            groups[temp]++;
            if (groups[temp] > largestGroupSize) {
                largestGroupSize = groups[temp];
                numLargestGroups = 1;
            } else if (groups[temp] == largestGroupSize) {
                numLargestGroups++;
            }
        }
        return numLargestGroups;
    }
};
