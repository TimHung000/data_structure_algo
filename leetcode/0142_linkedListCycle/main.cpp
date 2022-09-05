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
    ListNode *detectCycle(ListNode *head) {
        struct ListNode *fastPtr = head;
        struct ListNode *slowPtr = head;
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(fastPtr == slowPtr) {
                slowPtr = head;
                while(fastPtr != slowPtr) {
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                return fastPtr;
            }
        }
        return nullptr;
    }
    ListNode * detectCycle(ListNode *head) {
        std::unordered_set<struct ListNode*> hashSet;
        struct ListNode *ptr = head;
        while(ptr) {
            if(hashSet.find(ptr) != hashSet.end())
                return ptr;
            hashSet.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;

    }
};
