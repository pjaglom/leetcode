#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int count = 0;
        std::sort(nums.begin(), nums.end());
        
        for (int num : nums) {
            int localLower = lower - num;
            int localUpper = upper - num;
            int lowerIndex = -1;
            int upperIndex = -1;
            auto foundIter = find_if(nums.begin(), nums.end(), [num, lower](int candidate){return num + candidate >=lower;});
            if ((foundIter) != nums.end()) {
                lowerIndex = std::distance(nums.begin(), foundIter);
            } else {
                continue;
            }
            foundIter = find_if(nums.begin(), nums.end(), [num, upper](int candidate){return num + candidate <= upper;});
            if ((foundIter) != nums.end()) {
                upperIndex = std::distance(nums.begin(), foundIter);
            }
            if (upperIndex >= lowerIndex) {
                count += upperIndex - lowerIndex + 1;
            }
        }
        return count / 2;
    }
};

int main() {
    Solution solution;
    std::vector case1 = {0,1,7,4,4,5};
    std::cout << "[0,1,7,4,4,5]: " << solution.countFairPairs(case1, 3, 6) << "\n";
    std::vector case2 = {1,7,9,2,5};
    std::cout << "[1,7,9,2,5]: " << solution.countFairPairs(case2, 11, 11) << "\n";
}
