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
        ListNode *result = new ListNode();
        int temp = l1->val + l2->val;
        result->val = temp % 10;
        int carry = temp / 10;
        ListNode *current = result;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr && l2 != nullptr) {
            temp = l1->val + l2->val + carry;
            current->next = new ListNode(temp % 10);
            carry = temp / 10;
            l1 = l1->next;
            l2 = l2->next;
            current = current->next;
        }

        if (l1 == nullptr && l2 != nullptr) {
            while (l2 != nullptr) {
                temp = l2->val + carry;
                current->next = new ListNode(temp % 10);
                carry = temp / 10;
                l2 = l2->next;
                current = current->next;
            }
        }
        if (l2 == nullptr && l1 != nullptr) {
            while (l1 != nullptr) {
                temp = l1->val + carry;
                current->next = new ListNode(temp % 10);
                carry = temp / 10;
                l1 = l1->next;
                current = current->next;
            }
        }

        if (carry > 0) {
            current->next = new ListNode(carry % 10);
        }
        return result;
    }
};

