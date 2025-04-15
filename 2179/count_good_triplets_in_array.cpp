#include <iostream>

#include <unordered_map>
#include <vector>

class Solution {
public:

    long long goodTriplets(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> nums2_dict;
        for (long unsigned int i = 0; i < nums2.size(); i++) {
            nums2_dict[nums2[i]] = i;
        }

        int count = 0;
        for (long unsigned int i = 0; i < nums1.size() - 2; i++) {
            for (long unsigned int j = i + 1; j < nums1.size() - 1; j++) {
                for (long unsigned int k = j + 1; k < nums1.size(); k++) {
                    if (
                        nums2_dict[nums1[i]] < nums2_dict[nums1[j]] &&
                        nums2_dict[nums1[j]] < nums2_dict[nums1[k]]
                    ) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::vector<int> ex1_nums1 = {2,0,1,3};
    std::vector<int> ex1_nums2 = {0,1,2,3};
    std::cout << "Example 1: " << solution.goodTriplets(ex1_nums1, ex1_nums2) << "\n";

    std::vector<int> ex2_nums1 = {4,0,1,3,2};
    std::vector<int> ex2_nums2 = {4,1,0,2,3};
    std::cout << "Example 2: " << solution.goodTriplets(ex2_nums1, ex2_nums2) << "\n";
}
