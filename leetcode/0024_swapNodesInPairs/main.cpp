
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = nullptr;
        ListNode** indirectPtr = &res;
        ListNode* ptr = head;
        while(ptr && ptr->next) {
            ListNode* nextStart = ptr->next->next;
            *indirectPtr = ptr->next;
            indirectPtr = &(*indirectPtr)->next;
            *indirectPtr = ptr;
            indirectPtr = &(*indirectPtr)->next;
            ptr = nextStart;
        }

        *indirectPtr = ptr;

        return res;
    }
};

class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* dummyNode = new ListNode();
        ListNode* prevNode = dummyNode;
        ListNode* currNode = head;
        while(currNode && currNode->next) {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }

        currNode = dummyNode->next;
        delete dummyNode;
        return currNode;
    }
}

int main(int argc, char** argv) {
    ListNode *node5 = new ListNode(5);
    ListNode *node4 = new ListNode(4);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    Solution sol;
    ListNode * ans = sol.swapPairs(node1);
    return 0;
}
