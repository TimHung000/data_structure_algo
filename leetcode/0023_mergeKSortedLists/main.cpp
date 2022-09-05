#include <vector>
#include <queue>      //std::priority_queue
#include <functional> //std::function

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//brute force
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        ListNode** indirectPtr = &res;
        int sIndex = helper(lists);
        while(sIndex != -1) {
            *indirectPtr = lists[sIndex];
            lists[sIndex] = lists[sIndex]->next;
            indirectPtr = &(*indirectPtr)->next;
            sIndex = helper(lists);
        }
        return res;
    }

private:
    //find smallestHeadIndex
    int helper(std::vector<ListNode*>& lists) {
        int res = -1;
        for(int i = 0; i < lists.size(); ++i) {
            if(res == -1 && lists[i]) {
                res = i;
            }
            else if(res != -1 && lists[i]) {
                if(lists[i]->val < lists[res]->val) {
                    res = i;
                }
            }
        }

        return res;
    }
};

//recursion using merge2Lists
class Solution1 {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(!lists.size())
            return nullptr;

        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); ++i) {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = l1->val <= l2->val ? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        return head;
    }
};
//using priority queue
//complexity: nlog(k)
class Solution2 {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(!lists.size())
            return nullptr;

        auto cmp = [&](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        //priority queue as MIN HEAP
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
        //using the first node of all list to build MIN HEAP
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i])
                pq.push(lists[i]);
        }

        ListNode* res = nullptr;
        ListNode** indirectPtr = &res;

        while(!pq.empty()) {
            *indirectPtr = pq.top();
            pq.pop();

            if((*indirectPtr)->next)
                pq.push((*indirectPtr)->next);

            indirectPtr = &(*indirectPtr)->next;
        }
        return res;

    }
};


int main(int argc, char** argv) {
    ListNode* list1_3 = new ListNode(5);
    ListNode* list1_2 = new ListNode(4, list1_3);
    ListNode* list1_1 = new ListNode(1, list1_2);

    ListNode* list2_3 = new ListNode(4);
    ListNode* list2_2 = new ListNode(3, list2_3);
    ListNode* list2_1 = new ListNode(1, list2_2);

    ListNode* list3_2 = new ListNode(6);
    ListNode* list3_1 = new ListNode(2, list3_2);

    std::vector<ListNode*> test = { list1_1, list2_1, list3_1};

    Solution2 sol;
    ListNode* res = sol.mergeKLists(test);
    return 0;
}
