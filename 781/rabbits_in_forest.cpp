#include <iostream>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int min_rabbits = 0;
        std::unordered_map<int, int> unique_answers;
        for (int answer : answers) {
            if (answer == 0) {
                min_rabbits += 1;
            } else {
                unique_answers.insert({answer, 0});
                unique_answers[answer]++;
            }
        }
        for (auto [answer, count] : unique_answers) {
            min_rabbits += ((count + answer) / (answer + 1)) * (answer + 1); // weird division used to get ceiling of quotient instead of floor: q = (x + y - 1) / y
        }
        return min_rabbits;
    }
};

int main () {
    Solution solution;
    std::vector<int> failed_test = {0,1,0,2,0,1,0,2,1,1};
    std::cout << solution.numRabbits(failed_test) << "\n";
}
