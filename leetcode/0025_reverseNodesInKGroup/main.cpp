#include <iostream>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevEnd = dummy;
        ListNode* currStart = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(true){
            ListNode* ptr = currStart;
            for(int i = 0; i < k; i++){
                if(ptr == nullptr) {
                    ptr = dummy->next;
                    delete dummy;
                    return ptr;
                }
                ptr = ptr->next;
            }
            curr = currStart;
            prev = prevEnd;
            for(int i = 0; i < k; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            currStart->next = curr;
            prevEnd->next = prev;
            prevEnd = currStart;
            currStart = curr;
        }
    }

};

class Solution1 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
        listnode* ptr = head;
        for(int i = 0; i < k; i++){
            if(!ptr) return head;
            ptr = ptr->next;
        }
        listnode* prev = nullptr;
        listnode* curr = head;
        listnode* next = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reversekgroup(curr, k);
        return prev;
    }
}

void printList(ListNode *head) {
    while(head) {
        std::cout << head->val <<std::endl;
        head = head->next;
    }
}

int main(int argc, char** argv) {
    Solution sol;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* first = (ListNode*)malloc(sizeof(ListNode));
    ListNode* second = (ListNode*)malloc(sizeof(ListNode));
    ListNode* third = (ListNode*)malloc(sizeof(ListNode));
    ListNode* fourth = (ListNode*)malloc(sizeof(ListNode));
    head->val = 1;
    first->val = 2;
    second->val = 3;
    third->val = 4;
    fourth->val = 5;
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
//    printList(head);
    ListNode* test = sol.reverseKGroup(head, 2);
    printList(test);

    return 0;

}
