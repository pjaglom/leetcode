#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> dict;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto complement = dict.find(target - nums[i]);
            if (complement != dict.end()) {
                result = {i, complement->second};
                return result;
            }
            dict.insert({nums[i], i});
        }
        return result;
    }
};

