/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return new ListNode();

        ListNode* result = nullptr;
        int carry = 0;
        int sum = 0;

        if(l1) {
            sum = sum + l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum = sum + l2->val;
            l2 = l2->next;
        }

        ListNode* curNode = new ListNode(sum % 10);
        carry = sum / 10;
        result = curNode;

        while(l1 || l2 || carry) {
            sum = carry;
            if(l1) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curNode->next = new ListNode(sum % 10);
            curNode = curNode -> next;
        }

        return result;

    }
};
