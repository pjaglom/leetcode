#include <string>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int num2 = 0;
        int pow = 1;
        while (l1 != nullptr) {
            num1 += l1->val * pow;
            l1 = l1->next;
            pow *= 10;
        }
        pow = 1;
        while (l2 != nullptr) {
            num2 += l2->val * pow;
            l2 = l2->next;
            pow *= 10;
        }
        std::string sum_str = std::to_string(num1 + num2);
        ListNode *result = new ListNode(*(sum_str.rbegin()) - '0');
        ListNode *cur = result;
        for (std::string::reverse_iterator rit=sum_str.rbegin() + 1; rit!=sum_str.rend(); rit++) {
            ListNode *next = new ListNode(*rit - '0');
            cur->next = next;
        }
        return result;
    }
};
