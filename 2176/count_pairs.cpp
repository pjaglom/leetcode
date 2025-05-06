#include <vector>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int k) {
        int count;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] &&
                    ((i * j % k) == 0)) {
                    count++;
                }
            }
        }
        return count;
    }
};

