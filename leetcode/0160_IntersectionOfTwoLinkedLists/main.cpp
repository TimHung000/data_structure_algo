#include <cmath>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        int diff = 0;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(ptrA) {
            ++lenA;
            ptrA = ptrA -> next;
        }

        while(ptrB) {
            ++lenB;
            ptrB = ptrB ->next;
        }

        ptrA = headA;
        ptrB = headB;
        diff = std::abs(lenA - lenB);

        if(lenA > lenB) {
            while(diff > 0) {
                ptrA = ptrA->next;
                --diff;
            }
        }:
        else {
            while(diff > 0) {
                ptrB = ptrB->next;
                --diff;
            }
        }

        while(ptrA && ptrB) {
            if(ptrA == ptrB)
                return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return nullptr;

    }
};
