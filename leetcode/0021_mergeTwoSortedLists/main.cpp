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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = nullptr;
        ListNode** indirectPtr = &res;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                *indirectPtr = list1;
                list1 = list1->next;
            }
            else {
                *indirectPtr = list2;
                list2 = list2->next;
            }
            indirectPtr = &(*indirectPtr)->next;
        }
        if(list1) *indirectPtr = list1;
        if(list2) *indirectPtr = list2;
        return res;
    }

    ListNode* mergeTwoLists(ListNOde* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *tmp = dummy;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            }
            else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }

        if(list1) tmp->next = list1;
        if(list2) tmp->next = list2;
        tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};
